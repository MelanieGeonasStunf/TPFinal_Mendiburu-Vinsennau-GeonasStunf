///////////////////////////////////////////////////////////
//  Audio.cpp
//  Implementation of the Class Audio
//  Created on:      01-Jun-2021 10:50:03 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Audio.h"


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


RegistroAyV* Audio::RegistrarenRegistro(Usuarios* user) //no se si hay que pasarle el tiempo de reproduccion
{
	RegistroAyV* reg;
	reg = new RegistroAyV(user->FechayHoraCierre, tiempoReproduccion, user->UserName);

	/*
	tm fecha;
	cListaT<AudioVisual>* ListadeRecientesAyV;
	cListaT <Audio>* ListaRecientesA;//tenia doble puntero y le saque uno
	int MinutodeReproduccion;
	const string UserName;
	*/

}
