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
}
void Audio::IniciarServicio(Usuarios* user)
{ 
	/*user->setFHcierre(/*agrego 10s por ejemplo);*//*
	int option = 0;
	//option=0;//nada
	//option=1;//pausar
	//option=2;//adelantar
	do {
		int option = 1 + rand() % 4;
		switch (option)
		{
		case 1:
		case 2:
		case 3:
		}
	} while (option != 3);
	RegistroAyV* reg = RegistrarenRegistro(user);*/
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
