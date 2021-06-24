#pragma once
#include "Servicios.h"


class RegistroAyV;

class Audio :
    public Servicios
{
    tm duracion;
    tm tiempoInicio;
    int cantEscxPer;

public:
    Audio(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango,
        tm duracion);
    Audio(Audio& audio);
    virtual ~Audio();

    void FastBackward(long int& time,long int&TiempoR);//flecha abajo
    void FastForward(long int& time,long int&TiempoR);//flecha arriba
    void Record();//R
    void VelocidadReproduccion(int velocidad);
    void IniciarServicio();
    tm getTInicio() { return tiempoInicio; }
    tm getDuracion() { return duracion; }

    bool GuardartiempoRep( int seg);

    RegistroAyV* RegistrarenRegistro(Usuarios* user,bool visto);

    int getCant() { return cantEscxPer; }
    void setCant() { cantEscxPer++; }
};

