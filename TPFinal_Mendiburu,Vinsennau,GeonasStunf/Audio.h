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

    void FastBackward();//flecha abajo
    void FastForward();//flecha arriba
    void Record();//R
    void VelocidadReproduccion(int velocidad);
    void IniciarServicio();
    tm getTInicio() { return tiempoInicio; }
    tm getDuracion() { return duracion; }

    void GuardartiempoRep(RegistroAyV* reg, int seg);

    RegistroAyV* RegistrarenRegistro(Usuarios* user);
};

