///////////////////////////////////////////////////////////
//  RegistroAyV.h
//  Implementation of the Class RegistroAyV
//  Created on:      01-Jun-2021 10:50:21 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "AudioVisual.h"
#include "Audio.h"
#include "Librerias.h"

class RegistroAyV
{

public:
	RegistroAyV();
	virtual ~RegistroAyV();
	AudioVisual *m_AudioVisual;
	Audio *m_Audio;

private:
	tm Fecha;
	int ListadeRecientes;
	int MinutodeReproduccion;
	const string UserName;

};

