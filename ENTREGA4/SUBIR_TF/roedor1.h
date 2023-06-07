
#ifndef ROEDOR1_H
#define ROEDOR1_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <ctime>  //
#include <cstdlib> //
#include <iostream>
#include <chrono>

#include <QElapsedTimer>

#include <thread>
#include <chrono>;

#include "personajes.h"

class roedor1 : public QObject,   public QGraphicsItem, public personajes
{
    Q_OBJECT
private:
    QTimer *timer; //frecuencia de alternancia para las imagenes
    QTimer *timerDesplazarRaton; //para invocar metodo de CAMINA-AVANZAR

    QPixmap *pixmap; //para meter imagen

    float ancho, alto;  //variables para tamaños de las SUBIMAGENES-DIMENSIONES
    float filas,columnas; //para iterar por las secciones de la imagen

    float tiempoMuerto; //estatico
    //int tiempoMuerto; //estatico

    //+++++++++++++++bool perfilDerecho;
    bool perfilIzquierdo;

public:
    explicit roedor1(QObject *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    //void simularAvanceCanimarSaltar();

    void setPerfilIzquierdo(bool newPerfilIzquierdo);

    void setFilas(float newFilas);

signals:

public slots:
    void actialuzar();
    void simularAvanceCanimarSaltar2();


};

#endif // ROEDOR1_H
