#pragma once
#include "Servicios.h"


class RegistroAyV;

class Audio :
    public Servicios
{
    tm duracion;
    tm tiempoInicio;

public:
    Audio(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango,
        tm duracion);
    Audio(Audio& audio);
    virtual ~Audio();

    void FastBackward();
    void FastForward();
    void Record();
    void VelocidadReproduccion(int velocidad);
    void IniciarServicio();
    tm getTInicio() { return tiempoInicio; }

    RegistroAyV* RegistrarenRegistro(Usuarios* user);
};

