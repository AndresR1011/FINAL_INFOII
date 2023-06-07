
#ifndef ZORR_H
#define ZORR_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

#include "math.h"


#include "personajes.h"


class zorr : public QObject, public QGraphicsItem, public personajes
{
    Q_OBJECT
private:
    int cantidadPresas;
    float puntajeZorro;

    QTimer *timer; //caminar
    QTimer *timerSaltar; //para saltar;
    QPixmap *pixmap; //para meter imagen

    float filas,columnas; //para iterar por las secciones de la imagen PRINCIPAL
    float ancho, alto;  //variables para tamaños de las SUBIMAGENES-DIMENSIONES

    char letraCaminar;
    bool perfilDerecho; //Se usa para validar

    bool jump;
    bool moveRtn;

    //float posXZorro, posYZorro;
    //float velocidadZorro;
public:
    explicit zorr(QObject *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    void iniciar(void);//para pausas de tiempo //vinculado para onTimer(void)

    void simularAvanceCanimarSaltar();
    void saltarZorro();

    bool getPerfilDerecho() const;

    char getLetraCaminar() const;
    void setLetraCaminar(char newLetraCaminar);

    void setJump(bool newJump);

    void setFilas(float newFilas);

    void setPerfilDerecho(bool newPerfilDerecho);

    int getCantidadPresas() const;
    void setCantidadPresas(int newCantidadPresas);

    float getPuntajeZorro() const;
    void setPuntajeZorro(float newPuntajeZorro);

    void setMoveRtn(bool newMoveRtn);

signals:

public slots:
    void efectoCaminar();
    void efectoSaltar();
private slots:
    void onTimer(void); //viculado para  iniciar(void)


};

#endif // ZORR_H

