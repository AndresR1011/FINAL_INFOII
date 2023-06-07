
#include "pantalla.h"

pantalla::pantalla()
{

}

QRectF pantalla::boundingRect() const
{
    return QRectF(0,0,960,540);
}

void pantalla::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;


    //pixmap.load(":/imagenes/Escenas combinadas_marco.png");
    pixmap.load(":/pintura/escena1y2_y_nameJuego.png");

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

