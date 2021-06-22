///////////////////////////////////////////////////////////
//  AudioVisual.h
//  Implementation of the Class AudioVisual
//  Created on:      01-Jun-2021 10:50:04 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Servicios.h"
#include "Librerias.h"

class RegistroAyV;

class AudioVisual : public Servicios
{

private:
	bool HD;//true para usuarios premium nada mas
	int TipoAudioVisual; //ES UN ENUM?
	tm duracion;
	tm tiempoInicio;//cuenta el tiempo en que empieza a ver-> nos sirve para saber si vio todo el video

public:
	AudioVisual(const string clave, const string nombre, int cantP, Paises* paises, 
		RangoEtareo rango, tm duracion ,int Tipo );
	AudioVisual(AudioVisual& ayv);
	virtual ~AudioVisual();

	void setCalidad(bool hd) { HD = hd; }
	tm getTInicio() { return tiempoInicio; }

	void FastBackward();//flecha abajo
	void FastForward();//flecha arriba
	void Record();//R-> la verdad que ni idea con lo que podemos hacer aca
	void VelocidadReproduccion(int velocidad);//-> la vamos a hacer al final?
	void GuardartiempoRep(RegistroAyV* reg, int seg);
	void IniciarServicio();//empieza a contar el tiempo 
	
	
	RegistroAyV* RegistrarenRegistro(Usuarios* user);
	tm getDuracion() { return duracion; }
};
