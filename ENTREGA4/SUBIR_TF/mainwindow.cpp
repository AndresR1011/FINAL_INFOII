
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene(0,0,960,540);
    ui->graphicsView->setScene(scene); //agregar escena creada en el garficsView


    hzCaminar=new QTimer();
    connect(hzCaminar,SIGNAL(timeout()),this,SLOT(animar()));
    //timercaras->start(33);
    hzCaminar->start(20);

    temporizador = new QTimer ();

    fondo = new pantalla();
    scene->addItem(fondo);
    //++pantalla->setPos(0,0); //(20,20)
    fondo->setPos(-10,0); //(20,20)


    yen = new zorr();
    scene->addItem(yen);
    yen->setPos(yen->getPosicionX(),yen->getPosicionY());


    mouse = new roedor1();
    scene->addItem(mouse);
    //mouse->setPos(670, 435);
    mouse->setPos(mouse->getPosicionX(),mouse->getPosicionY());

    mouse2 = new roedor1();
    mouse2->setPerfilIzquierdo(false);
    mouse2->setFilas(50.5);
    mouse2->setPosicionX(310);
    scene->addItem(mouse2);
    //mouse->setPos(670, 435);
    mouse2->setPos(mouse2->getPosicionX(),mouse2->getPosicionY());

    mouse3 = new roedor1();
    mouse3->setPerfilIzquierdo(false);
    mouse3->setFilas(50.5);
    mouse3->setPosicionX(510);
    scene->addItem(mouse3);
    //mouse->setPos(670, 435);
    mouse3->setPos(mouse3->getPosicionX(),mouse3->getPosicionY());

    moverDerZorro= false, moverIzqZorro = false, saltarZorro= false, moverCaminarZ= false;
    //mouse->simularAvanceCanimarSaltar();
    //------------------------------mouse->simularAvanceCanimarSaltar2();

    //barra1=new QGraphicsRectItem(-30,-10,120,20);
    barra1=new QGraphicsRectItem(-30,-10,184,52);
    //barra1=new QGraphicsRectItem(92,10,184,20);
    scene->addItem(barra1);
    barra1->setPos(23,415);
    barra1->hide();
    //barra1=new QGraphicsRectItem(-30,-10,120,20);
    barra2=new QGraphicsRectItem(-30,-10,600,20);
    //barra1=new QGraphicsRectItem(92,10,184,20);
    scene->addItem(barra2);
    barra2->setPos(195,465);
    barra2->hide();
    barra3=new QGraphicsRectItem(-30,-10,184,52);
    //barra1=new QGraphicsRectItem(92,10,184,20);
    scene->addItem(barra3);
    barra3->setPos(790,416);
    barra3->hide();
}

MainWindow::~MainWindow()
{

    delete barra1;
    delete barra2;
    delete barra3;
    delete barra4;
    delete temporizador;
    delete fondo;
    delete mouse3;
    delete mouse2;
    delete mouse;
    delete yen;
    delete scene;
    delete ui;    
}

void MainWindow::animar()
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~yen->simularAvanceCanimarSaltar();
    if (saltarZorro != true){
        yen->simularAvanceCanimarSaltar();
    }
    else{
        yen->saltarZorro();
        saltarZorro = false;
    }

    /*
    if (saltarZorro==true){
        temporizador->setSingleShot(true);
        temporizador->start(2500);
        yen->setLetraCaminar('q');
    }*/

    if (yen->getPosicionY()>360){ //tope maximo en Y es de 365 ATRAPAR RATONES

        if(yen->collidesWithItem(mouse))
        {
            if(mouse->isVisible()){
                yen->setCantidadPresas(yen->getCantidadPresas()+1);
                mouse->hide();
                //emit aviso(9);
                //delete bola;
            }

        }
        if(yen->collidesWithItem(mouse2))
        {
            if(mouse2->isVisible()){
                yen->setCantidadPresas(yen->getCantidadPresas()+1);
                mouse2->hide();
                //emit aviso(9);
                //delete bola;
            }

        }

    }

    /*
    if(barra3->collidesWithItem(yen)){
        yen->setPosicionX(719);
        //yen

    }
    if (barra1->collidesWithItem(yen)){
        yen->setPosicionX(221);
    }*/
    //temporizador->setSingleShot(true); //------------------------
    //temporizador->start(2500);//------------------------
    //yen->setLugarY(315);

}


void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    //mouse->simularAvanceCanimarSaltar();
    if(ev->key()==Qt::Key_D)
    {
        yen->setFilas(460);
        yen->setLetraCaminar('d');
        yen->setPerfilDerecho(true);
        moverDerZorro = true;

        //yen->setLetraCaminar('d');
        //mouse->simularAvanceCanimarSaltar();


    }
    else if(ev->key()==Qt::Key_A)
    {
        yen->setFilas(690);
        yen->setLetraCaminar('a');
        yen->setPerfilDerecho(false);
        moverIzqZorro=true;

        //mouse->simularAvanceCanimarSaltar();

    }

    else if(ev->key()==Qt::Key_Space)
    {
        //mouse->simularAvanceCanimarSaltar();
        yen->setJump(true);

        if(yen->getPerfilDerecho()==true){
            yen->setFilas(0); //saltar imagen izquierda UBICAR SECCION DELA SUBIMAGEN
        }
        else{
            yen->setFilas(230); //saltar imagen derecha UBICAR SECCION DELA SUBIMAGEN
        }

        yen->setLetraCaminar('q');
        saltarZorro = true;

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~yen->setLetraCaminar(' '); //AVISA EFECTO PARA SALTAR



        //temporizador->setSingleShot(true); //------------------------
        //temporizador->start(1500);//------------------------

        //yen->setLetraCaminar('q');
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_D)
    {
        moverDerZorro = false;

        yen->setLetraCaminar('q');

    }
    else if(ev->key()==Qt::Key_A)
    {
        moverIzqZorro=false;
        yen->setLetraCaminar('q');
    }
    else if(ev->key()==Qt::Key_Space)
    {
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~temporizador->setSingleShot(true); //------------------------
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~temporizador->start(1500);//------------------------


        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~saltarZorro=false;
        //_sleep(2500);


        //+++++++++++yen->setLetraCaminar('q'); //al quitarlo se va saltando como loco
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~yen->setLetraCaminar('q');



    }


}

void MainWindow::aumentarPunt()
{
    //puntuacion += 5;
    yen->setPuntajeZorro((yen->getPuntajeZorro()+1));
    ui->lcdNumber->display(yen->getPuntajeZorro());
    //std::cout<<puntuacion<<std::endl;
}
