#include "myrect.h"
#include <QtGui>

class MyRect: public QGraphicsRectItem
{
    public:
        MyRect(qreal x, qreal y, qreal w, qreal h)
            : QGraphicsRectItem(x,y,w,h) {
            setAcceptHoverEvents(true);
            setBrush(Qt::green);
        }
    protected:
        void hoverEnterEvent(QGraphicsSceneHoverEvent *) {
            setBrush(Qt::red);
            update();
        }
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
            setBrush(Qt::green);
            update();
        }
};
