///////////////////////////////////////////////////////////
//  AudioVisual.h
//  Implementation of the Class AudioVisual
//  Created on:      01-Jun-2021 10:50:04 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Servicios.h"
#include "Librerias.h"

class AudioVisual : public Servicios
{

private:
	int Calidad;
	int TipoAudioVisual;
	tm duracion;

public:
	AudioVisual(const string clave,  const string nombre, Paises* paises, tm duracion ,int Tipo );
	virtual ~AudioVisual();

	void FastBackward();
	void FastForward();
	void Record();
	void VelocidadReproduccion(int velocidad);
	void MejorarCalidad(int calidad);
};
