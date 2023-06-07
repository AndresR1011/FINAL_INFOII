
#include "zorr.h"

bool zorr::getPerfilDerecho() const
{
    return perfilDerecho;
}


char zorr::getLetraCaminar() const
{
    return letraCaminar;
}

void zorr::setLetraCaminar(char newLetraCaminar)
{
    letraCaminar = newLetraCaminar;
}

void zorr::setJump(bool newJump)
{
    jump = newJump;
}

void zorr::setFilas(float newFilas)
{
    filas = newFilas;
}



void zorr::setPerfilDerecho(bool newPerfilDerecho)
{
    perfilDerecho = newPerfilDerecho;
}

int zorr::getCantidadPresas() const
{
    return cantidadPresas;
}

void zorr::setCantidadPresas(int newCantidadPresas)
{
    cantidadPresas = newCantidadPresas;
}

float zorr::getPuntajeZorro() const
{
    return puntajeZorro;
}

void zorr::setPuntajeZorro(float newPuntajeZorro)
{
    puntajeZorro = newPuntajeZorro;
}

void zorr::setMoveRtn(bool newMoveRtn)
{
    moveRtn = newMoveRtn;
}

zorr::zorr(QObject *parent)
    : QObject{parent}
{
    setNombre("1");
    setVelocidad(25);
    //setLugarX(70);
    setPosicionX(870); //maximoX = 870  //minimoX= 70
    setPosicionY(315);
    cantidadPresas =0;
    puntajeZorro =0.0;


    timerSaltar = new QTimer();
    timerSaltar->start(1000);

    //DIVIDIR IMAGEN PRINCIPAL EN filas y columnas
    pixmap = new QPixmap(":/pintura/ZORRO_caminaOK_saltaOk 850X920.png");   //se le pasa la direccion de meroria de la imagen
    filas=460;  //seccionar imagen principal en filas
    columnas =0; //seccionar imagen  principal en columnas
    ancho = 170;   //Dimensiones de las subimagen en X //BASE SUBIMAGEN
    alto = 230;    //Dimensiones de las subimagen en Y //ALTO SUBIMAGEN
    timer = new QTimer();
    timer->start(150); //milisegundos frecuancia de INTERCAMBIO DE SUBIMAGENES


    letraCaminar = 'q'; //ARRANACA  QUIETO
    perfilDerecho = true;   //ARRANCA VIENDO HACIA LA DERECHA

    jump =false;
    moveRtn = false;

    //Vincular timer con el slot efectoCaminar
    connect(timer,&QTimer::timeout,this,&zorr::efectoCaminar);

    //conmect(timerSaltar
    //{}{}{}{}{}{}connect(timerSaltar,&QTimer::timeout,this,&zorr::saltarZorro);
    connect(timerSaltar,&QTimer::timeout,this,&zorr::efectoSaltar);
}

void zorr::efectoCaminar()
{
    //ITERAR columnas de LA IMAGEN PRINCIPAL

    //if (letraCaminar == 'd' || letraCaminar == 'a'){// COLUMNAS CAMINAR: IZQUIERDA O DERECHA
    //~~~~~~~~~~~~~~if ((letraCaminar == 'd' || letraCaminar == 'a')){// COLUMNAS CAMINAR: IZQUIERDA O DERECHA
    if ((letraCaminar == 'd' || letraCaminar == 'a') && jump== false){// COLUMNAS CAMINAR: IZQUIERDA O DERECHA
        columnas +=170;
        if (columnas>= 850){
            //if (columnas>= 680){
            columnas =0;
        }
    }
    //~~~~~~~~~~~~~~else if (letraCaminar == 'q'){// COLUMNA ESTARSE QUIETO
    else if (letraCaminar == 'q' && jump== false){// COLUMNA ESTARSE QUIETO
        columnas +=170;
        //if (columnas>= 850){
        if (columnas>= 170){
            columnas =0;
        }
    }

    //~~~~~~~~~~~~~~else if (letraCaminar== ' ' ) { //COLUMNAS PARA SALTAR
    else if (letraCaminar== 'q' && jump==true ) { //COLUMNAS PARA SALTAR
        //filas=25;
        columnas += 170;

        if (columnas>= 850){
            columnas =0;
        }
        //_sleep(0);
    }

    this->update(-ancho/2, -alto/2, ancho,alto);
}

void zorr::efectoSaltar()
{
    //~~~~~~~~~~~~~~else if (letraCaminar== ' ' ) { //COLUMNAS PARA SALTAR
    if (letraCaminar== 'q' && jump==true ) { //COLUMNAS PARA SALTAR
        //filas=25;
        columnas += 170;

        if (columnas>= 850){
            columnas =0;
        }
        //_sleep(0);
    }
}

void zorr::onTimer()
{

}

QRectF zorr::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho,alto);
}

void zorr::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,filas,ancho,alto);
}

void zorr::iniciar()
{
    QTimer::singleShot(500, this, SLOT(onTimer())); //timepo de pausa
}

void zorr::simularAvanceCanimarSaltar()
{

    float tiempo = 0.25;
    float tmpX=getPosicionX(); //auxiliar de posicionn inicial


    //if (letraCaminar=='a' && perfilDerecho==false ){ //DESPALZAMIENTO hacia IZQUIERDA
    if ((letraCaminar=='a' && perfilDerecho==false ) && jump==false){ //DESPALZAMIENTO hacia IZQUIERDA
        //timer->start(150);
        float pasos= getVelocidad()*tiempo;
        //..............................................if(tmpX-pasos<=65){ //NO AVANZA MAS DE ESA POSICION
        if(tmpX-pasos<=65){ //NO AVANZA MAS DE ESA POSICION
            setPos(getPosicionX(),getPosicionY()); //ACTUALIZA POSCION EN ESCENA
            //moveRtn=false;

        }else{ //AVANZA IZQUIERDA
            /*
            if (getLugarY()>= 365){
                setPos(getLugarX(),getLugarY());
            }else{
                setLugarX(tmpX-pasos);

                setPos(getLugarX(),getLugarY()); //ACTUALIZA POSCION EN ESCENA
            }*/
            setPosicionX(tmpX-pasos);

            setPos(getPosicionX(),getPosicionY()); //ACTUALIZA POSCION EN ESCENA
        }
        //setLugarX(tmpX-pasos);
        //setPos(getLugarX(),getLugarY()); //ACTUALIZA POSCION EN ESCENA


    }
    //else if (letraCaminar=='d'&& perfilDerecho==true){ //DESPALZAMIENTO hacia DERECHA
    else if ((letraCaminar=='d'&& perfilDerecho==true) && jump==false){ //DESPALZAMIENTO hacia DERECHA
        //timer->start(150);
        float pasos= getVelocidad()*tiempo;
        if(tmpX+pasos >= 872){ //NO AVANZA MAS DE ESA POSICION
            setPos(getPosicionX(),getPosicionY()); //ACTUALIZA POSCION EN ESCENA
            //moveRtn = false;

        }
        else{//AVANZA DERECHA

            setPosicionX(tmpX+pasos);

            setPos(getPosicionX(),getPosicionY());//ACTUALIZA POSCION EN ESCENA
        }
        //setLugarX(tmpX+pasos);
        //setPos(getLugarX(),getLugarY());//ACTUALIZA POSCION EN ESCENA

    }
    /*
    //if(letraCaminar==' ' && perfilDerecho==true){
    if(letraCaminar==' ' && perfilDerecho==true ){
        //timer->start(500);
        saltarZorro();

    }
    if (letraCaminar==' ' && perfilDerecho==false){


        setPos(getLugarX(),getLugarY());


    }
    */
}


void zorr::saltarZorro()
{
    const float piNumero=3.141592;
    //----------float tiempo = 3.5;
    float tiempo = 4.0;
    float gravedad = 9.8;
    float angulo=65;

    float xLugarTMP= getPosicionX(); //AUXILIAR PARA POSCION INICIAL en X
    float ylugarTMP = getPosicionY();  //AUXILIAR PARA POSCION INICIAL en Y


    float velo=20.0; //VELOCIDAD DE ENNSAYO-PRUEBA



    if(letraCaminar=='q' && perfilDerecho==true && jump==true){

        //---------for (float i=0.0; i <= tiempo; i+=0.25){
        for (float i=0.0; i <= tiempo; i+=0.25){
            if(getPosicionY()>= 365 || (getPosicionX()<=220 && getPosicionX()>=720)){


                //setLugarY(315);
                break;
            }
            float xFinal = xLugarTMP + velo*tiempo*cos(angulo*piNumero/180.0); //calcular poscion X
            float yFinal = ylugarTMP - velo*tiempo*sin(angulo*piNumero/180.0)+(gravedad*(tiempo*tiempo))/2.0; //calcular posicion Y
            setPosicionX(xFinal);
            setPosicionY(yFinal);
            setPos(getPosicionX(),getPosicionY());
            //_sleep(50);
            iniciar();
        }


        //letraCaminar='q';
        if(getPosicionY()>=364){
            iniciar();
            iniciar();
            iniciar();
            iniciar();
            setPosicionY(315);
            setPos(getPosicionX(),getPosicionY());

        }


        jump=false;

    }
    else if(letraCaminar=='q' && perfilDerecho==false && jump==true){
        jump=false;
    }

}
