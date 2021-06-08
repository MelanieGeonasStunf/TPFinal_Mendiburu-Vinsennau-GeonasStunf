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
#include"cListaT.h"

class RegistroAyV
{

private:
	tm Fecha;
	cListaT<AudioVisual>* ListadeRecientesAyV;
	cListaT <Audio>* ListaRecientesA;//tenia doble puntero y le saque uno
	int MinutodeReproduccion;
	const string UserName;

public:
	RegistroAyV(const string Name);
	virtual ~RegistroAyV();

	RegistroAyV* RegistrarenRegistro();

};

