
#include "jugar.h"

void jugar::setModalidaJuego(bool newModalidaJuego)
{
    modalidaJuego = newModalidaJuego;
}

void jugar::agregarRatonLista()
{
    if (listaRoedores.size() == 0){
        list<roedor1>::iterator indexLista;

    }
}

void jugar::eliminarRoedor(string nombreRoedor)
{
    list<roedor1>::iterator indexL;
    indexL = listaRoedores.begin();
    bool bandera= false;

    while((indexL != listaRoedores.end())  && bandera!=true){
        //if (indexL->getNombre() == roe->getNombre()){
        if (indexL->getNombre() == nombreRoedor){
            listaRoedores.erase(indexL);
            bandera = true;
            //break;
        }
        indexL++;
    }
}

float jugar::calcularPuntaje()
{
    float puntateF=0;
    if (modalidaJuego==true){
        //puntateF = lobito->getCantidadPresas()*1.1 + 3 temporizador;
    }

}

jugar::~jugar()
{
    delete lobito;
}

float jugar::getTemporizador() const
{
    return temporizador;
}

int jugar::ratonesAleatorios()
{
    srand(time(NULL));

    int num = rand()%4 +1;

    return num;
}

jugar::jugar()
{
    modalidaJuego = true; //facil
    cantidadRoedores = ratonesAleatorios();
    puntajeFinal =0.0;

    lobito = new zorr();
    //listaRoedores = NULL;


}

