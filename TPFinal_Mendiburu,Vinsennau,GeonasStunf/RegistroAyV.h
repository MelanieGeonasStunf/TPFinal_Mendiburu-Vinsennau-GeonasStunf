#pragma once

#include "Librerias.h"
#include "Audio.h"
#include "AudioVisual.h"

class RegistroAyV
{

private:
	static int counter;
	const string clave;
	tm Fecha;
	tm tiempoReproduccion;
	bool Visto;//vio + 30% ->lo vio
	const string UserName;
	friend class Audio;
	friend class AudioVisual;

public:
	RegistroAyV(const string Name);
	virtual ~RegistroAyV();

	string getclave() const { return clave; };


};

