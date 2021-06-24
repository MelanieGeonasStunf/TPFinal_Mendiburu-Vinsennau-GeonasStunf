#pragma once

//#include "Librerias.h"
#include "Audio.h"
#include "AudioVisual.h"

class RegistroAyV
{

private:
	static int counter;
	const string clave;
	tm Fecha;
	//tm tiempoReproduccion;
	bool Visto;//vio + 30% ->lo vio
	string Nombre;
	const string UserName;
	friend class Audio;
	friend class AudioVisual;

public:
	RegistroAyV(string nom, const string Name, bool visto);
	virtual ~RegistroAyV();

	string getclave() const { return clave; };
	tm getFecha() { return Fecha; }
	string getNombre() { return Nombre; }
};

