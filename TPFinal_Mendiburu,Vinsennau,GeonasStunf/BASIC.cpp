///////////////////////////////////////////////////////////
//  BASIC.cpp
//  Implementation of the Class BASIC
//  Created on:      01-Jun-2021 10:49:59 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "BASIC.h"


BASIC::BASIC(int Edad, Paises Pais, string Password, const string Name, string tarjeta):
	Usuarios(Edad, Pais, Password, Name)
{
	//inicializar tarjeta
}

BASIC::~BASIC(){

}


void BASIC::Registrarse(){

}

void BASIC::SeleccionarServicio(cListaT<Servicios>* servicio)
{
}

