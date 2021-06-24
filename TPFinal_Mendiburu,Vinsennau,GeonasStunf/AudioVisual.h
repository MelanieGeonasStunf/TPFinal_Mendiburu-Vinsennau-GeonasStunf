#pragma once

#include "Servicios.h"
//#include "Librerias.h"

class RegistroAyV;

class AudioVisual : public Servicios
{

private:
	bool HD;//true para usuarios premium nada mas
	int TipoAudioVisual; //ES UN ENUM?
	tm duracion;
	tm tiempoInicio;//cuenta el tiempo en que empieza a ver-> nos sirve para saber si vio todo el video
	int cantVisxPer;

public:
	AudioVisual(const string clave, const string nombre, int cantP, Paises* paises, 
		RangoEtareo rango, tm duracion ,int Tipo );
	AudioVisual(AudioVisual& ayv);
	virtual ~AudioVisual();

	void setCalidad(bool hd) { HD = hd; }
	tm getTInicio() { return tiempoInicio; }

	void FastBackward(long int& time,long int&TiempoR);//flecha abajo
	void FastForward(long int& time,long int&TiempoR);//flecha arriba
	void Record();//R-> la verdad que ni idea con lo que podemos hacer aca
	void VelocidadReproduccion(int velocidad);//-> la vamos a hacer al final?
	bool GuardartiempoRep( int seg);
	void IniciarServicio();//empieza a contar el tiempo 
	
	
	RegistroAyV* RegistrarenRegistro(Usuarios* user,bool visto);
	tm getDuracion() { return duracion; }

	void setCant() { cantVisxPer++; }
	int getCant() { return cantVisxPer; }
};
