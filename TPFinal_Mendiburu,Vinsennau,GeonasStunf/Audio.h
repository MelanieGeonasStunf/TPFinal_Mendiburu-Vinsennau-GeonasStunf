#pragma once
#include "Servicios.h"


class RegistroAyV;

class Audio :
    public Servicios
{
    tm duracion;
public:
    Audio(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango,
        tm duracion);
    virtual ~Audio();

    void FastBackward();
    void FastForward();
    void Record();
    void VelocidadReproduccion(int velocidad);
    void IniciarServicio( Usuarios* user);

    RegistroAyV* RegistrarenRegistro(Usuarios* user);
};

