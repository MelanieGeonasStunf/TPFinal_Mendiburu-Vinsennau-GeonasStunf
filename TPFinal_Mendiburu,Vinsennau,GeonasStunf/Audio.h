#pragma once
#include "Servicios.h"

class Audio :
    public Servicios
{
public:
    Audio(const string clave, tm duracion, const string nombre, Paises* paises);
    virtual ~Audio();

    void FastBackward();
    void FastForward();
    void Record();
    void VelocidadReproduccion(int velocidad);
};

