///////////////////////////////////////////////////////////
//  RegistroAyV.h
//  Implementation of the Class RegistroAyV
//  Created on:      01-Jun-2021 10:50:21 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Librerias.h"
#include "Audio.h"
#include "AudioVisual.h"

class RegistroAyV
{

private:
	tm Fecha;
	tm tiempoReproduccion;
	bool Visto;//vio + 30% ->lo vio
	const string UserName;
	friend class Audio;
	friend class AudioVisual;

public:
	RegistroAyV(const string Name);
	virtual ~RegistroAyV();


};

