
#ifndef JUGAR_H
#define JUGAR_H

#include <iostream>

#include <ctime>
#include <cstdlib>
#include <list>

#include "zorr.h"
#include "roedor1.h"

using namespace std;

/*
struct roedor{
    roedor1 raton;
};*/

class jugar
{

private:
    float temporizador;
    bool modalidaJuego;
    int cantidadRoedores;
    float puntajeFinal;
    zorr *lobito;
    list<roedor1> listaRoedores;



    int ratonesAleatorios();
public:
    jugar();
    void setModalidaJuego(bool newModalidaJuego);
    void agregarRatonLista();
    void eliminarRoedor(string nombreRoedor);
    float calcularPuntaje();

    ~jugar();
    float getTemporizador() const;
};

#endif // JUGAR_H
