///////////////////////////////////////////////////////////
//  AudioVisual.cpp
//  Implementation of the Class AudioVisual
//  Created on:      01-Jun-2021 10:50:04 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "AudioVisual.h"
#include "RegistroAyV.h"
class Usuario;

AudioVisual::AudioVisual(const string clave, const string nombre, int cantP, 
	Paises* paises, RangoEtareo rango, tm duracion, int Tipo )
	:Servicios( clave, nombre, cantP, paises,rango)
{
	this->duracion = duracion;
	TipoAudioVisual = Tipo;//tendriamos que poner el tipo como enum o dejarlo en int?
	HD = false;

}

AudioVisual::~AudioVisual(){

}





void AudioVisual::FastBackward(){

}


void AudioVisual::FastForward(float velocidad, tm tiempo){
	//tiempo es el tiempo que quiere hacer fast forward.
	int seg = difftime(0, mktime(&tiempo));//chequear si funciona
	//float min = seg * 60;
	int seg2 = difftime(0, mktime(&duracion));

	if (seg > seg2)
	{
		//hace fast forward de todo el video

	}

	

}


void AudioVisual::Record(){

}


void AudioVisual::VelocidadReproduccion(int velocidad){

}


void AudioVisual::GuardartiempoRep(RegistroAyV* reg)
{
	//int seg = rand() % duracion.tm_sec;
	//int min = rand() % duracion.tm_min;
	int hs = rand() % duracion.tm_hour;
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


RegistroAyV* AudioVisual::RegistrarenRegistro(Usuarios* user)
{
	RegistroAyV* reg;
	reg = new RegistroAyV(user->FechayHoraCierre, tiempoReproduccion, user->UserName);

	return reg;
}
