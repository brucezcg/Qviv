/*
 * Copyright (C) 2011 Dov Grobgeld <dov.grobgeld@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#include <QvivImageViewer.h>
#include <QPen>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>
#include <QScrollBar>
#include <math.h>
#include <stdio.h>

#define DBG(a) a
#define DBG2(a) 

class QvivImageViewer::Priv 
{
public:
    QvivImageViewer *widget;
    QImage image;
    double current_scale_x;
    double current_scale_y;
    int current_x0;
    int current_y0;
    int scroll_width;
    int scroll_height;
    double scroll_min_x;
    double scroll_min_y;
    double scroll_max_x;
    double scroll_max_y;
    bool do_flip_horizontal;
    bool do_flip_vertical;
    bool frozen;
    bool do_use_transfer_map;
    double max_zoom;
    double min_zoom;
    bool do_linear_zoom_steps;
    bool is_mouse_scrolling;
    int last_pan_anchor_x;
    int last_pan_anchor_y;
    bool first_time; // Used in resize to fill image on first resize

    int view_changed(int do_force,
                     double scale_x,
                     double scale_y,
                     double x0,
                     double y0);

};

QvivImageViewer::QvivImageViewer(QWidget *parent,
                                 QImage image)
    : QAbstractScrollArea(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    d = new Priv;
    d->widget = this;
    d->image = image;
    d->scroll_width = image.width();
    d->scroll_height = image.height();
    d->current_scale_x = 1;
    d->current_scale_y = 1;
    d->current_x0 = 0;
    d->current_y0 = 0;
    d->do_flip_horizontal = false;
    d->do_flip_vertical = false;
    d->frozen = false;
    d->do_use_transfer_map = false;
    d->min_zoom = -1;
    d->max_zoom = -1;
    d->do_linear_zoom_steps = false;
    d->is_mouse_scrolling = false;
    d->last_pan_anchor_x = -1;
    d->last_pan_anchor_y = -1;
    d->scroll_min_x=0;
    d->scroll_min_y=0;
    d->scroll_max_x = image.width();
    d->scroll_max_y = image.height();
    d->first_time = true;

    setMouseTracking(true);
}

QvivImageViewer::~QvivImageViewer()
{
    delete d;
}

QSize QvivImageViewer::sizeHint() const
{
    return QSize(d->image.width(), d->image.height());
}

// See: http://doc.trolltech.com/4.5/painting-basicdrawing.html
// for more examples!
void QvivImageViewer::paintEvent(QPaintEvent *evt)
{
    printf("paintEvent\n");
    QPainter painter(d->widget->viewport());
    painter.setClipRegion(evt->region());
    int exp_x0 = evt->rect().x();
    int exp_y0 = evt->rect().y();
    int w = evt->rect().width();
    int h = evt->rect().height();
    printf("expose %d %d %d %d\n", exp_x0, exp_y0, w,h);
    double scale_x = d->current_scale_x;
    double scale_y = d->current_scale_y;
    int exp_x1 = exp_x0 + w;
    int exp_y1 = exp_y0 + h;
    int offs_x = -d->current_x0-exp_x0;
    int offs_y = -d->current_y0-exp_y0;
    double trans_offs_x = offs_x;
    double trans_offs_y = offs_y;
    int dst_x = exp_x0;
    int dst_y = exp_y0;
    int copy_w = w;
    int copy_h = h;
    int cnv_w = this->size().width();
    int cnv_h = this->size().height();

    /* A scaled and cropped version of the image */
    QImage img_scaled;

#if 0
    // This doesn't work yet. If the adjustments changed then there
    // is no reason to expose.
    if (update_adjustments(self))
      return;
#endif

    if (d->image.width()) {
  				/* Canvas size */
        int img_w, img_h;		/* Image's size (pixels) */
        int img_x0 = 0;
        int img_x1 = cnv_w;
        int img_y0 = 0;
        int img_y1 = cnv_h;
        img_w = d->image.width();
        img_h = d->image.height();
        DBG(fprintf(stderr, "current_x0 exp_x0 offs_x = %d %d %d\n",
                    d->current_x0,
                    exp_x0,
                    offs_x));
  
        /* If img fits in canvas horizontally, need a smaller drawing zone */
        if (img_w * scale_x < cnv_w) {
            img_x0 = ((cnv_w - img_w*scale_x)/2);
            img_x1 = (img_x0 + img_w*scale_x);
        }
        
        /* If img fits in canvas vertically : need a smaller drawing zone */
        if (img_h * scale_y < cnv_h) {
            img_y0 = ((cnv_h - img_h*scale_y)/2);
            img_y1 = (img_y0 + img_h*scale_y);
        }
        
        if (exp_x1 < img_x0) {
            DBG(fprintf(stderr, "Case 1X\n"));
            copy_w = 0;
            offs_x = 0;
            dst_x = img_x0;
#if 0
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,w, h);
#endif
        }
        else if (exp_x0 < img_x0 && exp_x1 > img_x1) {
            DBG(fprintf(stderr, "Case 2X\n"));
            copy_w = w - (img_x0 - exp_x0) - (exp_x1 - img_x1);
            dst_x = img_x0;

            if (d->do_flip_horizontal) {
                trans_offs_x = d->current_x0+exp_x0+cnv_w-img_x0;
                offs_x = 0;
            }
            else
                trans_offs_x = offs_x = 0;
            
#if 0            
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,(img_x0-exp_x0), h);
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               img_x1,exp_y0,(exp_x1-img_x1), h);
#endif
        }
        else if (exp_x0 < img_x0) {
            DBG(fprintf(stderr, "Case 3X\n"));
            copy_w = w - (img_x0 - exp_x0);
            dst_x = img_x0;

            if (d->do_flip_horizontal) {
                offs_x = (-(img_w*scale_x-(exp_x1-img_x0)));
                trans_offs_x = d->current_x0+cnv_w-img_x0;
            }
            else
                offs_x = trans_offs_x = 0;
            
#if 0
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,(img_x0-exp_x0), h);
#endif
        }
        else if (exp_x0 > img_x1) {
#if 0
            DBG(fprintf(stderr, "Case 4X\n"));
            copy_w = 0;
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,w, h);
            
#endif
        }
        else if (exp_x1 > img_x1) {
            DBG(fprintf(stderr, "Case 5X\n"));
            copy_w = w - (exp_x1 - img_x1);
            dst_x = exp_x0;

            if (d->do_flip_horizontal) {
                trans_offs_x = d->current_x0-exp_x0+cnv_w;
                offs_x = 0;
            }
            else
              offs_x = trans_offs_x = -(exp_x0-img_x0);
            
#if 0
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               img_x1,exp_y0,exp_x1-img_x1, h);
#endif
        }
        else {
            DBG(fprintf(stderr, "Case 6X\n"));
            dst_x = exp_x0;
            copy_w = w;
            
            if (d->do_flip_horizontal) {
                offs_x = -(cnv_w + d->current_x0 - exp_x1);
                trans_offs_x = d->current_x0-exp_x0+cnv_w;
            }
            else
                offs_x = trans_offs_x = -d->current_x0-exp_x0;
        }
  
        /* Y dir */
        if (exp_y1 < img_y0) {
            DBG(fprintf(stderr, "Case 1Y\n"));
            copy_h = 0;
            offs_y = 0;
            dst_x = img_y0;
#if 0
            gdk_draw_rectangle(widget->window,
  			     widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,w, h);
#endif
        }
        else if (exp_y0 < img_y0 && exp_y1 > img_y1) {
            DBG(fprintf(stderr, "Case 2Y\n"));
            copy_h = h - (img_y0 - exp_y0) - (exp_y1 - img_y1);
            dst_y = img_y0;
            
            if (d->do_flip_vertical) {
                trans_offs_y = d->current_y0+exp_y0+cnv_h-img_y0;
                offs_y = 0;
            }
            else
              trans_offs_y = offs_y = 0;
            
#if 0
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,w, img_y0-exp_y0);
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0, img_y1,w, exp_y1-img_y1);
#endif
        }
        else if (exp_y0 < img_y0) {
            DBG(fprintf(stderr, "Case 3Y\n"));
            copy_h = h - (img_y0 - exp_y0);
            dst_y = img_y0;
            
            if (d->do_flip_vertical) {
                offs_y = (-(img_h*scale_y-(exp_y1-img_y0)));
                trans_offs_y = d->current_y0+cnv_h-img_y0;
            }
            else
                offs_y = trans_offs_y = 0;

#if 0
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,w,(img_y0-exp_y0));
#endif
        }
        else if (exp_y0 > img_y1) {
            DBG(fprintf(stderr, "Case 4Y\n"));
            copy_h = 0;
#if 0
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,exp_y0,w, h);
#endif            
        }
        else if (exp_y1 > img_y1) {
            DBG(fprintf(stderr, "Case 5Y\n"));
            copy_h = h - (exp_y1 - img_y1);
            dst_y = exp_y0;

            if (d->do_flip_vertical) {
                trans_offs_y = d->current_y0-exp_y0+cnv_h;
                offs_y = 0;
            }
            else
                offs_y = trans_offs_y = -(exp_y0-img_y0);
            
#if 0
            gdk_draw_rectangle(widget->window,
                               widget->style->bg_gc[GTK_WIDGET_STATE (widget)],
                               TRUE,
                               exp_x0,img_y1,w,exp_y1-img_y1);
#endif
        }
        else {
            DBG(fprintf(stderr, "Case 6Y\n"));
            dst_y = exp_y0;
            copy_h = h;

            if (d->do_flip_vertical) {
                offs_y = -(cnv_h + d->current_y0 - exp_y1);
                trans_offs_y = d->current_y0-exp_y0+cnv_h;
            }
            else
                offs_y = trans_offs_y = -d->current_y0-exp_y0;
        }
  
        DBG(fprintf(stderr, "dst_x dst_y copy_w copy_h offs_x offs_y = %d %d %d %d %d %d\n",
  	      dst_x, dst_y, copy_w, copy_h,
  	      d->current_x0, d->current_y0));

        if (copy_w > 0 && copy_h > 0) {
            // Where to copy from taking margin into account
            int src_offs_x = (int)floor(-offs_x/scale_x);
            int src_offs_y = (int)floor(-offs_y/scale_y);
            int end_offs_x = (int)ceil((-offs_x+copy_w)/scale_x);
            int end_offs_y = (int)ceil((-offs_y+copy_h)/scale_y);

            // The extra offset we need to transpose after scaling
            int copy_start_offs_x = (int)(-offs_x - src_offs_x * scale_x);
            int copy_start_offs_y = (int)(-offs_y - src_offs_y * scale_y);
            int copy_scale_width = (int)((end_offs_x - src_offs_x) * scale_x);
            int copy_scale_height = (int)((end_offs_y - src_offs_y)*scale_y);

            // Is there a faster way of doing this than these three
            // operators?
            img_scaled = d->image.copy(src_offs_x,
                                       src_offs_y,
                                       end_offs_x-src_offs_x,
                                       end_offs_y-src_offs_y);
            printf("copy: src_offs_x src_offs_y scale_x scale_y=%d %d %f %f\n",src_offs_x, src_offs_y,scale_x,scale_y);
            img_scaled = img_scaled.scaled(copy_scale_width,
                                           copy_scale_height);
            img_scaled = img_scaled.copy(copy_start_offs_x,
                                         copy_start_offs_y,
                                         copy_w,
                                         copy_h);

            /* Check legality */
            DBG(fprintf(stderr, "offs_x copy_x scale_x w = %d %d %f %d\n",
                        offs_x, copy_w, scale_x, img_w));

            if (d->do_use_transfer_map) {
#if 0
                /* Assume we are doing 8-bit... */
                guint8 *buf_scaled = gdk_pixbuf_get_pixels(img_scaled);
                gint w = gdk_pixbuf_get_width(img_scaled);
                gint h = gdk_pixbuf_get_height(img_scaled);
                gint rs = gdk_pixbuf_get_rowstride(img_scaled);
                gint row_idx, col_idx;
                guint8 *rmap = d->transfer_map[0];
                guint8 *gmap = d->transfer_map[1];
                guint8 *bmap = d->transfer_map[2];
                
                for (row_idx=0; row_idx<h; row_idx++)
                  {
                    guint8 *p = &buf_scaled[rs*row_idx];
                    
                    for (col_idx=0; col_idx<w; col_idx++)
                      {
                        *p = rmap[*p]; p++;
                        *p = gmap[*p]; p++;
                        *p = bmap[*p]; p++;
                      }
                  }
#endif
            }
            if (d->do_flip_vertical || d->do_flip_vertical)
                img_scaled = img_scaled.mirrored(d->do_flip_horizontal,
                                                 d->do_flip_vertical);
        }
    }

#if 0
    // If we are working without a background image then create one
    // now for the painting.
    if (!img_scaled) {
        img_scaled = gdk_pixbuf_new(GDK_COLORSPACE_RGB,
                                    TRUE,
                                    8,
                                    w, h);
        if (d->do_flip_horizontal)
          offs_x = d->current_x0+w-exp_x1+cnv_w;
        else
          offs_x = -d->current_x0-exp_x0;
        DBG(printf("No image: current_x0=%d offs_x = %d\n", d->current_x0, offs_x));
        if (d->do_flip_vertical)
          offs_y = d->current_y0+h-exp_y1+cnv_h;
        else
          offs_y = -d->current_y0-exp_y0;
        dst_x = exp_x0;
        dst_y = exp_y0;
        copy_w = w;
        copy_h = h;

        gdk_pixbuf_fill(img_scaled,
                        0xffffffff);
    }
    else {
        offs_x = trans_offs_x;
        offs_y = trans_offs_y;
    }
#endif
          
    // Image annotation signal

    // Add checkerboard below images that have alpha channel
    if (img_scaled.hasAlphaChannel()) {
        // TBD
    } 
    if (!d->frozen)
        painter.drawImage(QRect(dst_x,dst_y,copy_w,copy_h),
                          img_scaled);
}

void QvivImageViewer::mousePressEvent (QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    printf("button=%d\n",event->button());
    if (event->button() == 1)
        this->zoom_in((int)x, (int)y, 2);
    else if (event->button() == 4) {
        d->is_mouse_scrolling = true;
        d->last_pan_anchor_x = x;
        d->last_pan_anchor_y = y;
    }
    else if (event->button() == 2)
        this->zoom_out((int)x, (int)y, 2);
  
}

void QvivImageViewer::mouseReleaseEvent (QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if (event->button() == 4
        && d->is_mouse_scrolling) {
        d->is_mouse_scrolling = false;

  	if (d->last_pan_anchor_x>0 && d->last_pan_anchor_y > 0)
  	    this->zoom_translate((int)(d->last_pan_anchor_x-x),
                                 (int)(d->last_pan_anchor_y-y));
    }
}

void QvivImageViewer::mouseMoveEvent (QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if (d->is_mouse_scrolling) {
        if (d->last_pan_anchor_x>0 && d->last_pan_anchor_y > 0) {
            printf("mouseMoveEvent: lpx,lpy,x,y=%d,%d,%d,%d\n",
                   d->last_pan_anchor_x,
                   d->last_pan_anchor_y,
                   x,
                   y);
            int dx = (int)(d->last_pan_anchor_x-x);
            int dy = (int)(d->last_pan_anchor_y-y);

            if (d->do_flip_horizontal)
              dx = -dx;
            if (d->do_flip_vertical)
              dy = -dy;
            this->zoom_translate(dx, dy);
          }
        
        d->last_pan_anchor_x = x;
        d->last_pan_anchor_y = y;
    }
}

/*======================================================================
//  view_changed does clipping, scrolling and scaling.
//----------------------------------------------------------------------
*/
int
QvivImageViewer::Priv::view_changed(int do_force,
                                    double scale_x,
                                    double scale_y,
                                    double x0,
                                    double y0)
{
  QRect expose_rect;
  int render_width, render_height;

  DBG2(g_print("force sx sy x0 y0 = %d %f %f %f %f\n",
	       do_force, scale_x, scale_y, x0, y0));

  /* Clip the scale */
  if (this->max_zoom > 0 && scale_x>this->max_zoom && scale_y > this->max_zoom)
      return 0;
  else if (this->min_zoom > 0 && scale_x < this->min_zoom && scale_y < this->min_zoom)
      return 0;

  /* Clip the request */
  if (this->image.width()
      || (this->scroll_width > 0 && this->scroll_height > 0)
      ) {
    int cwidth = widget->viewport()->size().width();
    int cheight = widget->viewport()->size().height();
        
    double width = this->scroll_width;
    double height = this->scroll_height;
        
    if (width*scale_x > cwidth)
        render_width = cwidth;
    else
        render_width = (int)(width * scale_x);
        
    if (height*scale_y > cheight)
        render_height = cheight;
    else
        render_height = (int)(height * scale_y);
        
    // Clip only for images
    if (this->image.width()) {
      if (render_width < cwidth)
          x0 = -(cwidth - render_width)/2;
      else if (x0 + render_width > width*scale_x)
          x0 = width*scale_x - render_width;
      else if (x0<0)
          x0 = 0;
            
      if (image.width() && render_height < cheight)
          y0 = -(cheight - render_height)/2;
      else if (y0 + render_height > height*scale_y)
          y0 = height*scale_y - render_height;
      else if (y0<0)
          y0 = 0;
    }
  }
  
  /* If scale is the same, then the image has only been scrolled,
     and we only need to update the exposed areas.
  */
  if (!do_force
      && scale_x == this->current_scale_x
      && scale_y == this->current_scale_y
      ) {
    double dx = (x0 - this->current_x0);
    double dy = (y0 - this->current_y0);

    // Scroll in opposite direction if we are flipping
    if (this->do_flip_horizontal)
        dx = -dx;
    if (this->do_flip_vertical)
        dy = -dy;
    int src_x = (dx < 0) ? 0 : dx;
    int src_y = (dy < 0) ? 0 : dy;
    int dst_x = (dx < 0) ? -dx : 0;
    int dst_y = (dy < 0) ? -dy : 0;

    this->current_x0 = x0;
    this->current_y0 = y0;
    printf("view changed current_x0 dx y0 dy= %d %d %d %d\n",
           (int)this->current_x0, (int)dx,
           (int)this->current_y0, (int)dy
           );

    /* Scroll visible region */
    printf("scroll: %d,%d\n", dst_x-src_x,dst_y-src_y);
    widget->viewport()->scroll(dst_x-src_x,dst_y-src_y);

    DBG2(g_print("Filling in: dx dy = %d %d\n", dx, dy));
    /* And fill in the new areas */
    if (dx) {
      int x = (dx < 0) ? 0 : widget->viewport()->size().width() - dx;
      int width = abs(dx);
      int height = widget->viewport()->size().height();

      widget->viewport()->update(x,0,width,height);
    }
    if (dy) {
      int y = (dy < 0) ? 0 : widget->viewport()->size().height() - dy;
      int width = widget->viewport()->size().width();
      int height = abs(dy);
          
      widget->viewport()->update(0,y,width,height);
    }
  }
  
  else if ((do_force
            || scale_x != this->current_scale_x
            || scale_y != this->current_scale_y
            || x0 != this->current_x0
            || y0 != this->current_y0))
      {
        /* Remember the current transform */
        this->current_scale_x = scale_x;
        this->current_scale_y = scale_y;
        this->current_x0 = (int)x0;
        this->current_y0 = (int)y0;

        widget->viewport()->update();
      }

  // Update scrollbars
  QSize areaSize = widget->viewport()->size();
  
  widget->verticalScrollBar()->setPageStep(this->scroll_width);
  widget->horizontalScrollBar()->setPageStep(this->scroll_height);
  widget->verticalScrollBar()->setRange(0, this->scroll_height*scale_y - areaSize.height());
  widget->horizontalScrollBar()->setRange(0, this->scroll_width*scale_y - areaSize.width());
  widget->horizontalScrollBar()->setValue(x0);
  widget->verticalScrollBar()->setValue(y0);

  return 1;
}

/*======================================================================
//  gtk_image_viewer_zoom_around_fixed_point is a preprocessor
//  to view_changed that allows a zooming while moving an old pixel
//  coordinate to a given new position. E.g. moving the x,y coordinate
//  clicked by the mouse to the center of the zoomed up image.
//----------------------------------------------------------------------
*/
int
QvivImageViewer::zoom_around_fixed_point(double new_scale_x,
                                         double new_scale_y,
                                         double old_x,
                                         double old_y,
                                         double new_x,
                                         double new_y)
{
    int cnv_w = this->size().width();
    int cnv_h = this->size().height();
    double old_scale_x, old_scale_y, old_x0, old_y0, new_x0, new_y0;
    DBG(printf("zoom_around_fixed_point: nsx nsy old_x old_y new_x new_y = %f %f  %f %f  %f %f\n",
               new_scale_x, new_scale_y,
               old_x, old_y,
               new_x, new_y));
    
    /* Short cuts */
    old_x0 = d->current_x0;
    old_y0 = d->current_y0;
    old_scale_x = d->current_scale_x;
    old_scale_y = d->current_scale_y;
    
    if (d->do_flip_horizontal) {
        old_x = cnv_w - old_x;
        new_x = cnv_w - new_x;
    }
    if (d->do_flip_vertical) {
        old_y = cnv_h - old_y;
        new_y = cnv_h - new_y;
    }
    
    new_x0 = new_scale_x/old_scale_x * (old_x + old_x0) - new_x;
    new_y0 = new_scale_y/old_scale_y * (old_y + old_y0) - new_y;
    
    DBG(printf("old_x0 new_x0 = %f %f\n", old_x0, new_x0));
    d->view_changed(FALSE, new_scale_x, new_scale_y, new_x0, new_y0);
    
    return 0;
}

int
QvivImageViewer::zoom_in(int x, int y, double factor)
{
  double zoom_factor[2];
  int zoom_idx;
  if (factor < 0)
    factor = 1.1;
  
  zoom_factor[0] = d->current_scale_x;
  zoom_factor[1] = d->current_scale_y;
  
  for (zoom_idx = 0; zoom_idx < 2; zoom_idx++) {
      double z = zoom_factor[zoom_idx];  /* A shortcut */
      if (d->do_linear_zoom_steps) {
        if (z < 0.5)
          z = 1.0 / (1.0/z-1);
        else
          z = z+1;
      }
      else 
        z *= factor;
      zoom_factor[zoom_idx] = z;
  }
  
  if (x<0)
      x = this->size().width()/2;
  if (y<0)
      y = this->size().height()/2;
  
  this->zoom_around_fixed_point(zoom_factor[0],
                                zoom_factor[1],
                                x, y,
                                this->size().width()/2,
                                this->size().height()/2);
  
  return 1;
}

int
QvivImageViewer::zoom_out(int /*x*/, int /*y*/, double factor)
{
  double zoom_factor[2];
  int zoom_idx;
  
  if (factor<0)
    factor = 1.1; 
  
  zoom_factor[0] = d->current_scale_x;
  zoom_factor[1] = d->current_scale_y;
  
  for (zoom_idx = 0; zoom_idx < 2; zoom_idx++) {
      double z = zoom_factor[zoom_idx];  /* A shortcut */
      if (d->do_linear_zoom_steps) {
        if (z <= 1.0)
            z = 1.0 / (1.0/z+1);
        else
            z = z-1;
      }
      else 
          z /= factor;
      zoom_factor[zoom_idx] = z;
  }
  
  this->zoom_around_fixed_point(zoom_factor[0],
                                zoom_factor[1],
                                this->size().width()/2,
                                this->size().height()/2,
                                this->size().width()/2,
                                this->size().height()/2
                                );
  return 1;
}
    
int
QvivImageViewer::zoom_translate(int dx, int dy)
{
    printf("zoom_translate %d %d\n", dx,dy);
    d->view_changed(false,
                    d->current_scale_x,
                    d->current_scale_y,
                    d->current_x0+dx,
                    d->current_y0+dy);
    return 1;
}

int QvivImageViewer::zoom_to_box(double world_min_x,
                                 double world_min_y,
                                 double world_max_x,
                                 double world_max_y,
                                 double pixel_margin,
                                 bool preserve_aspect)
{
    double w = d->widget->viewport()->width();
    double h = d->widget->viewport()->height();

    double new_scale_x = (w-2*pixel_margin)/(world_max_x-world_min_x);
    double new_scale_y = (h-2*pixel_margin)/(world_max_y-world_min_y);
      
    if (preserve_aspect) {
        if (new_scale_x > new_scale_y)
            new_scale_x = new_scale_y;
        else
            new_scale_y = new_scale_x;
    }
    // This works for both flip and not flip!
    double new_x0 = new_scale_x*0.5*(world_max_x+world_min_x)-w/2;
    double new_y0 = new_scale_y*0.5*(world_max_y+world_min_y)-h/2;

    d->view_changed(false, new_scale_x, new_scale_y, new_x0, new_y0);
      
    return 0;
}
  
void QvivImageViewer::zoom_fit(void)
{
    zoom_to_box(d->scroll_min_x,
                d->scroll_min_y,
                d->scroll_max_x,
                d->scroll_max_y,
                0,
                true);
}

void QvivImageViewer::zoom_reset(void)
{
    d->view_changed(true, 1, 1, 0, 0);
}

void QvivImageViewer::resizeEvent ( QResizeEvent * /*event */)
{
    if (d->first_time) {
        zoom_fit();
        d->first_time= false;
    }
}

void QvivImageViewer::wheelEvent (QWheelEvent *event)
{
    if (event->delta() < 0)
        zoom_out(event->x(),event->y(),1.1);
    else
        zoom_in(-1,-1,1.1);
}

void QvivImageViewer::keyPressEvent (QKeyEvent * event)
{
    QString k = event->text();

    if (k=="=" || k=="+")
        zoom_in(-1, -1, 1.1);
    else if (k==">")
        zoom_in(-1, -1, 2);
    else if (k=="<")
        zoom_out(-1, -1, 2);
    else if (k=="-")
        zoom_out(0, 0, 1.1);
    else if (k=="1"||k=="n")
        zoom_reset();
    else if (k=="f")
        zoom_fit();
#if 0
    else if (k=="v")
        set_flip(d->do_flip_horizontal,
                 !d->do_flip_vertical);
    else if (k=="h")
        set_flip(!d->do_flip_horizontal,
                 d->do_flip_vertical);
#endif
}

// Map scrollbar changes to internal view changes
void QvivImageViewer::scrollContentsBy (int /*dx*/, int /*dy*/)
{
    d->view_changed(false,
                    d->current_scale_x,
                    d->current_scale_y,
                    horizontalScrollBar()->value(),
                    verticalScrollBar()->value());
}
