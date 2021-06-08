#pragma once
#include "Servicios.h"

class Audio :
    public Servicios
{
    tm duracion;
public:
    Audio(const string clave, const string nombre, Paises* paises, tm duracion);
    virtual ~Audio();

    void FastBackward();
    void FastForward();
    void Record();
    void VelocidadReproduccion(int velocidad);

    RegistroAyV* RegistrarenRegistro();
};

