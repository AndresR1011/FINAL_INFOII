
#ifndef PANTALLA_H
#define PANTALLA_H

#include <QGraphicsItem>
#include <QPainter>


class pantalla : public QGraphicsItem
{
public:
    pantalla();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PANTALLA_H
