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

public:
	AudioVisual();
	virtual ~AudioVisual();

	void FastBackward();
	void FastForward();
	void Record();
	void VelocidadReproduccion();

private:
	int Calidad;
	int TipoAudioVisual;

};
