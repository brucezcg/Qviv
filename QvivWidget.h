// A widget like GivWidget
#ifndef QVIVWIDGET_H
#define QVIVWIDGET_H

#include <QWidget>
#include "QvivImageViewer.h"

class QvivData;

class QvivWidget : public QvivImageViewer {
    Q_OBJECT 

public:
    QvivWidget(QWidget *parent,
               QImage image );
    ~QvivWidget();
    void set_qviv_data(QvivData *qviv_data);

    // Let the user pick a point with the mouse and returns the chosen
    // point. Returns 0 if a point was chosen with the mouse. Returns
    // -1 if Escape was pressed to indicate aborting the picking.
    int pick_point(// output
                   QPointF& picked_point);
    int rubber_band_pick(QPointF start_point,
                         // output
                         QPointF& picked_point);
    void set_view_overlay(bool do_view_overlay);
    void set_view_balloon(bool do_view_overlay);
    void abort_pick_point(void);
    bool is_measuring(void);
      
protected:
    void keyPressEvent (QKeyEvent * event);
    void mousePressEvent (QMouseEvent * event);
    void mouseReleaseEvent (QMouseEvent * event);
    void imageAnnotate(QImage*, int, int, double, double);
    void mouseMoveEvent (QMouseEvent *event);
    void leaveEvent(QEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    void qvivOverlayChanged(bool view_overlay);
    void qvivBalloonChanged(bool view_overlay);

private:
    class Priv;
    Priv *d;
};


#endif /* QVIVWIDGET */
