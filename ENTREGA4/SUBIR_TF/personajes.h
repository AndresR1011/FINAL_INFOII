
#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <string>

using namespace std;


class personajes
{
protected:
    string nombre;
    float velocidad;
    float posicionX;
    float posicionY;
public:
    personajes();
    string getNombre() const;
    void setNombre(const string &newNombre);
    float getVelocidad() const;
    void setVelocidad(float newVelocidad);
    float getPosicionX() const;
    void setPosicionX(float newPosicionX);
    float getPosicionY() const;
    void setPosicionY(float newPosicionY);
};

#endif // PERSONAJES_H
