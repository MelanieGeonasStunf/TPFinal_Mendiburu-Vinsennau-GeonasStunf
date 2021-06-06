///////////////////////////////////////////////////////////
//  AudioVisual.cpp
//  Implementation of the Class AudioVisual
//  Created on:      01-Jun-2021 10:50:04 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "AudioVisual.h"



AudioVisual::AudioVisual(const string clave,  const string nombre, Paises* paises, tm duracion, int Tipo )
	:Servicios( clave, nombre,  paises)
{
	this->duracion = duracion;
	TipoAudioVisual = Tipo;//tendriamos que poner el tipo como enum o dejarlo en int?
	//Calidad depende del servicio o le ponemos lo que nos pinte?
}

AudioVisual::~AudioVisual(){

}





void AudioVisual::FastBackward(){

}


void AudioVisual::FastForward(){

}


void AudioVisual::Record(){

}


void AudioVisual::VelocidadReproduccion(int velocidad){

}

void AudioVisual::MejorarCalidad(int calidad)
{
}
