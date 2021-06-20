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
	int TipoAudioVisual;
	tm duracion;
	tm tiempoInicio;//cuenta el tiempo en que empieza a ver-> nos sirve para saber si vio todo el video

public:
	AudioVisual(const string clave, const string nombre, int cantP, Paises* paises, 
		RangoEtareo rango, tm duracion ,int Tipo );
	AudioVisual(AudioVisual& ayv);
	virtual ~AudioVisual();

	void FastBackward();
	void FastForward(float velocidad, tm tiempo);
	void Record();
	void VelocidadReproduccion(int velocidad);
	void setCalidad(bool hd) { HD = hd; }
	void GuardartiempoRep(RegistroAyV* reg);
	void IniciarServicio();
	tm getTInicio() { return tiempoInicio; }
	
	RegistroAyV* RegistrarenRegistro(Usuarios* user);
	tm getDuracion() { return duracion; }
};
