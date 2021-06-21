///////////////////////////////////////////////////////////
//  Audio.cpp
//  Implementation of the Class Audio
//  Created on:      01-Jun-2021 10:50:03 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Audio.h"
#include "RegistroAyV.h"
#include "funciones.h"

Audio::Audio(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango, tm duracion)
	:Servicios(clave, nombre, cantP, paises, rango)
{
	this->duracion = duracion;
	this->tiempoInicio = { 0,0,0 };
}
Audio::Audio(Audio& audio):Servicios(audio), duracion(audio.duracion)
{
}
void Audio::IniciarServicio()
{ 
	time_t rawtime;
	tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	tiempoInicio = *info;
}

Audio::~Audio(){

}





void Audio::FastBackward(){

}


void Audio::FastForward(){

}


void Audio::Record(){

}


void Audio::VelocidadReproduccion(int velocidad){

}


void Audio::GuardartiempoRep(RegistroAyV* reg, int seg)
{
	//int seg = rand() % duracion.tm_sec;
	//int min = rand() % duracion.tm_min;
	long int durSeg = PasarAseg(duracion);
	if (0.3 * durSeg >= seg)
		reg->Visto = true;
	/*int hs = rand() % duracion.tm_hour;
	if (hs == duracion.tm_hour)
	{
		int min = rand() % duracion.tm_min;
		if (min == duracion.tm_min)
		{
			int seg = rand() % duracion.tm_sec;
			//Si el usuario vio mas del 30% -> tomamos como video visto.
			int tiempoRep = hs * 10000 + min * 1000 + seg;
			int tiempoTotal = duracion.tm_hour * 10000 + duracion.tm_min * 1000 + duracion.tm_sec;

			tm tiempoR = { hs, min, seg };
			reg->tiempoReproduccion = tiempoR;

			if (tiempoRep == tiempoTotal * 0.3)
			{
				//significa que vio el 30% del video
				reg->Visto = true;
			}
		}
		return;
	}

	int min = rand() % duracion.tm_min;
	if (min == duracion.tm_min)
	{
		if (min == duracion.tm_min)
		{
			int seg = rand() % duracion.tm_sec;

			int tiempoRep = hs * 10000 + min * 1000 + seg;
			int tiempoTotal = duracion.tm_hour * 10000 + duracion.tm_min * 1000 + duracion.tm_sec;

			tm tiempoR = { hs, min, seg };
			reg->tiempoReproduccion = tiempoR;

			if (tiempoRep == tiempoTotal * 0.3)
			{
				//significa que vio el 30% del video
				reg->Visto = true;
			}
		}

		return;
	}

	int seg = rand() % duracion.tm_sec;
	int tiempoRep = hs * 10000 + min * 1000 + seg;
	int tiempoTotal = duracion.tm_hour * 10000 + duracion.tm_min * 1000 + duracion.tm_sec;

	tm tiempoR = { hs, min, seg };
	reg->tiempoReproduccion = tiempoR;

	if (tiempoRep == tiempoTotal * 0.3)
	{
		//significa que vio el 30% del video
		reg->Visto = true;
	}

}

void AudioVisual::IniciarServicio()
{
	time_t rawtime;
	tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	tiempoInicio = *info;

}


RegistroAyV* AudioVisual::RegistrarenRegistro(Usuarios* user)
{
	RegistroAyV* reg;
	reg = new RegistroAyV(user->FechayHoraCierre, tiempoReproduccion, user->UserName);

	return reg;*/
}

RegistroAyV* Audio::RegistrarenRegistro(Usuarios* user) //no se si hay que pasarle el tiempo de reproduccion
{
	RegistroAyV* reg;
	reg = new RegistroAyV(user->getFechayHoraCierre(), tiempoReproduccion, user->getUserName());

	/*
	tm fecha;
	cListaT<AudioVisual>* ListadeRecientesAyV;
	cListaT <Audio>* ListaRecientesA;//tenia doble puntero y le saque uno
	int MinutodeReproduccion;
	const string UserName;
	*/

}
