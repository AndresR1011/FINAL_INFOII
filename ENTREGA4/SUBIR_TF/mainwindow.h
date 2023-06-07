
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QGraphicsScene>

#include <qmath.h>
#include <QtMath>


#include <QKeyEvent>

#include "pantalla.h"
#include "zorr.h"
#include "roedor1.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();
    void aumentarPunt();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    pantalla* fondo;
    //zorro *fox;
    zorr *yen;
    roedor1 *mouse;
    roedor1 *mouse2;
    roedor1 *mouse3;

    bool moverDerZorro, moverIzqZorro, saltarZorro, moverCaminarZ;

    QTimer *hzCaminar;
    QTimer *temporizador;//para el salto

    QGraphicsRectItem* barra1;
    QGraphicsRectItem* barra2;
    QGraphicsRectItem* barra3;
    QGraphicsRectItem* barra4;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
};

#endif // MAINWINDOW_H
