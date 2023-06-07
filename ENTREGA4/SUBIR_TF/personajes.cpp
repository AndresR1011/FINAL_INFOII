
#include "personajes.h"

string personajes::getNombre() const
{
    return nombre;
}

void personajes::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

float personajes::getVelocidad() const
{
    return velocidad;
}

void personajes::setVelocidad(float newVelocidad)
{
    velocidad = newVelocidad;
}

float personajes::getPosicionX() const
{
    return posicionX;
}

void personajes::setPosicionX(float newPosicionX)
{
    posicionX = newPosicionX;
}

float personajes::getPosicionY() const
{
    return posicionY;
}

void personajes::setPosicionY(float newPosicionY)
{
    posicionY = newPosicionY;
}

personajes::personajes()
{
    nombre = "1";
    velocidad =0.0;
    posicionX = 0.0;
    posicionY = 0.0;
}

