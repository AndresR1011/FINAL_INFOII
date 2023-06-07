
#include "roedor1.h"

void roedor1::setPerfilIzquierdo(bool newPerfilIzquierdo)
{
    perfilIzquierdo = newPerfilIzquierdo;
}

void roedor1::setFilas(float newFilas)
{
    filas = newFilas;
}

roedor1::roedor1(QObject *parent)
    : QObject{parent}
{
    setNombre("1");
    setVelocidad(5.0);
    setPosicionX(725-25); //tope derecha
    setPosicionY(435);
    //tiempoMuerto = 0.0; //flotante
    tiempoMuerto = 0;
    //+++++++++++++++perfilDerecho = true;
    perfilIzquierdo = true;



    timer = new QTimer(); //ALTERNANCIA IMAGENES SPRITE
    timer->start(150); //milisegundos
    timerDesplazarRaton = new QTimer(); //REALIZARA CAMINATA
    //----------------------------------------------------------------------timerDesplazarRaton->start(100);
    timerDesplazarRaton->start(100);

    filas =0;     //seccionar imagen principal en filas
    columnas =0;  //seccionar imagen  principal en columnas

    pixmap = new QPixmap(":/pintura/SPLITE_ROEDOR_PNG.png"); //se le pasa la direccion de meroria de la imagen


    //Dimensiones de las subimagen
    ancho = 70;   //Dimensiones de las subimagen en X
    alto = 50.5;  //Dimensiones de las subimagen en Y



    //Vinculat timer con el slot ACTUALIZACION
    connect(timer,&QTimer::timeout,this,&roedor1::actialuzar);
    //+++++++++++++++connect(timer,&QTimer::timeout,this,&roedor::simularAvanceCanimarSaltar2);
    connect(timerDesplazarRaton,&QTimer::timeout,this,&roedor1::simularAvanceCanimarSaltar2);
}

void roedor1::actialuzar()
{
    //ITERAR POR LAS COLUMNAS DE LA IMAGEN PRINCIPAL
    columnas +=70;
    if (columnas>= 420){
        columnas =0;
    }

    this->update(-ancho/2, -alto/2, ancho,alto);
}

void roedor1::simularAvanceCanimarSaltar2()
{
    /*
    //+++++++++++++++float lapsoDesplazar= 0.3;
    float lapsoDesplazar= 300; //trayecto
    //+++++++++++++++float tiempoDistancia= 0.11;
    float tiempoDistancia= 8.8;
    float tempX= getLugarX();
    float pasos=0;



    //if (moverse!=false){
    //+++++++++++++++if(perfilDerecho==true){
    if(perfilIzquierdo==true){
        for (float i=0; i<=lapsoDesplazar; i+=0.06 ){



            //+++++++++++++++if (getLugarX()<=210){
            if (getLugarX()<=210 ||getVelocidad()*tiempoDistancia <= 210 ){
                moverse = false;
                //+++++++++++++++perfilDerecho =false;
                perfilIzquierdo = false;
                filas=50.5;
                break;
            }else{
                pasos = getVelocidad()*tiempoDistancia;
                setLugarX(tempX-pasos);
                setPos(getLugarX(),getLugarY()); //ACTUALIZA POSCION EN ESCENA
            }
            //+++++++++++++++pasos = getVelocidad()*tiempoDistancia;
            //+++++++++++++++setLugarX(tempX-pasos);
            //+++++++++++++++setPos(getLugarX(),getLugarY()); //ACTUALIZA POSCION EN ESCENA


        }
    }

    //+++++++++++++++if (perfilDerecho!=true) {
    if (perfilIzquierdo!=true) {
        for (float i=0; i<=lapsoDesplazar; i+=0.15 ){

            if (getLugarX()>=730){
                moverse = false;
                //+++++++++++++++perfilDerecho =true;
                perfilIzquierdo = true;
                filas=0;
                break;
            }
            else{
                pasos = getVelocidad()*tiempoDistancia;
                setLugarX(tempX+pasos);
                setPos(getLugarX(),getLugarY()); //ACTUALIZA POSCION EN ESCENA
            }
            //+++++++++++++++pasos = getVelocidad()*tiempoDistancia;
            //+++++++++++++++setLugarX(tempX+pasos);
            //+++++++++++++++setPos(getLugarX(),getLugarY()); //ACTUALIZA POSCION EN ESCENA

        }
    }
    */

    /*
    int temporalX= getLugarX();
    float tiempotrayecto=1.0;
    float paso= getLugarX() * tiempotrayecto;*/

    if (perfilIzquierdo==true){
        //_____________________________________________________________________________________________________
        /*
        float tiempotrayecto=0.00005;
        //for  (float i = 0; i<= 190; i+=0.4){
        for  (float i = 0; i<= 20; i+=0.025){
            float temporalX= getLugarX();
            float paso= getLugarX() * tiempotrayecto;
            if(temporalX-paso <= 215){
                perfilIzquierdo = false;
                filas =50.5; //PONE AL FILA PARA CAMINAR HACIA LA DERECHA
                break;
            }else{
              setLugarX(getLugarX()-paso);
            }
            setPos(getLugarX(), getLugarY());
        }*/
        //_____________________________________________________________________________________________________

        //--------------------------------------------------------------------------------

        float paso = getVelocidad()*0.8;

        if (getPosicionX()-paso >=220){
            setPosicionX(getPosicionX()-paso);
        }
        else{
            perfilIzquierdo = false;
            filas =50.5; //PONE AL FILA PARA CAMINAR HACIA LA DERECHA
        }
        setPos(getPosicionX(), getPosicionY());
        //--------------------------------------------------------------------------------

        /*do{
            setLugarX(temporalX-paso);
            setPos(getLugarX(), getLugarY());
            temporalX= getLugarX();
            paso= getLugarX() * tiempotrayecto;
        }while (getLugarX()>=220 && (getLugarX()- paso>=220));*/


        /*while (getLugarX()>=220 && (getLugarX()- paso>=220)){
            setLugarX(temporalX-paso);
            setPos(getLugarX(), getLugarY());
            temporalX= getLugarX();
            paso= getLugarX() * tiempotrayecto;
        }*/

        /*
        int temporalX= getLugarX();
        float tiempoTrayecto = 0.02;
        float paso= getLugarX() * tiempoTrayecto;

        while ((temporalX-paso)>=220){
            setLugarX(temporalX-paso);
            setPos(getLugarX(), getLugarY());
            temporalX = getLugarX();
            paso = getLugarX() * tiempoTrayecto;
        }*/

        //perfilIzquierdo = false;
    }
    else {
        //_____________________________________________________________________________________________________
        /*
        float tiempotrayecto=0.00005;
        //for  (float i = 0; i<= 190; i+=0.4){
        for  (float i = 0; i<= 20; i+=0.025){
            float temporalX= getLugarX();
            float paso= getLugarX() * tiempotrayecto;
            if(temporalX+paso >= 720){
              perfilIzquierdo = true;
              filas =0; //PONE AL FILA PARA CAMINAR HACIA LA DERECHA
              break;
            }else{
              setLugarX(getLugarX()+paso);
            }
            setPos(getLugarX(), getLugarY());
        }*/
        //_____________________________________________________________________________________________________

        //--------------------------------------------------------------------------------

        float paso = getVelocidad()*0.8;

        if (getPosicionX()+paso <=725){
            setPosicionX(getPosicionX()+paso);
        }
        else{
            perfilIzquierdo = true;
            filas =0; //PONE AL FILA PARA CAMINAR HACIA LA IZQUIERDA
        }
        setPos(getPosicionX(), getPosicionY());
        //--------------------------------------------------------------------------------

        /*do{
            setLugarX(temporalX+paso);
            setPos(getLugarX(), getLugarY());
            temporalX= getLugarX();
            paso= getLugarX() * tiempotrayecto;
        }while (getLugarX()<=700 && (getLugarX()+ paso<=700));*/


        /*while (getLugarX()<=700 && (getLugarX()+ paso<=700)){
            setLugarX(temporalX+paso);
            setPos(getLugarX(), getLugarY());
            temporalX= getLugarX();
            paso= getLugarX() * tiempotrayecto;
        }*/

        /*
        int temporalX= getLugarX();
        float tiempoTrayecto = 0.02;
        float paso= getLugarX() * tiempoTrayecto;

        for(float i=getLugarX(); i<= 710; i+=1.5){

        }

        while ((temporalX+paso)<=720){
            setLugarX(temporalX-paso);
            setPos(getLugarX(), getLugarY());
            temporalX = getLugarX();
            paso = getLugarX() * tiempoTrayecto;
        }*/

        //perfilIzquierdo = false;
    }
}

QRectF roedor1::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho,alto);
}

void roedor1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);
    painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,filas,ancho,alto);
}

/*
void roedor::simularAvanceCanimarSaltar()
{

}
*/
