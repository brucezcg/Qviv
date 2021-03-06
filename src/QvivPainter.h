//======================================================================
//  GivPainter.h - A virtual base class for painting in a QImage
//
//  Dov Grobgeld <dov.grobgeld@gmail.com>
//  Tue Nov  6 22:01:52 2007
//----------------------------------------------------------------------

#ifndef QVIVPAINTER_H
#define QVIVPAINTER_H

#include "QvivData.h"
#include "agg/agg_svg_path_renderer.h"

class QvivPainter {
 public:
    QvivPainter() {}
    virtual ~QvivPainter() {}

    virtual void set_set_idx(int /*set_idx*/) {}
    virtual void set_color(double red,
                           double green,
                           double blue,
                           double alpha=1.0) = 0;
    virtual int set_line_width(double line_width) = 0;
    virtual int set_font_size(double font_size_in_points) = 0;
    virtual int set_font(const char* font) = 0;
    virtual int add_mark(QvivMarkType mark_type,
                         double mark_size_x, double mark_size_y,
                         double x, double y) = 0;
    virtual int add_line_segment(double x0, double y0,
                                 double x1, double y1,
                                 bool do_polygon = 0) = 0;
    virtual void close_path(void) = 0;

    virtual int add_text(const char *text,
                         double x, double y,
                         int text_align,
                         bool do_pango_markup) = 0;
    virtual int add_sprite(const QImage *sprite,
                           double x, double y,
                           double sx, double sy) = 0;
    virtual void draw_marks() = 0;
    virtual void fill() = 0;
    virtual void stroke() = 0;
    virtual void set_dashes(int num_dashes,
                            double* dashes) = 0;
    virtual void set_arrow(bool do_start_arrow,
                           bool do_end_arrow,
                           double arrow_d1=-1,
                           double arrow_d2=-1,
                           double arrow_d3=-1,
                           double arrow_d4=-1,
                           double arrow_d5=-1
                           )=0;
    virtual void render_svg_path(agg::svg::path_renderer*svg,
                                 double mx, double my,
                                 double scalex, double scaley) = 0;
};

#endif /* QVIVPAINTER */
