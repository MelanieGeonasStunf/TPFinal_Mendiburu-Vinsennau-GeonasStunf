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

