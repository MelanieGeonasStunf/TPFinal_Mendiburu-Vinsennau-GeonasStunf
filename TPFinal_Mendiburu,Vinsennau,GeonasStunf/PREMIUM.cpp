///////////////////////////////////////////////////////////
//  PREMIUM.cpp
//  Implementation of the Class PREMIUM
//  Created on:      01-Jun-2021 10:50:00 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "PREMIUM.h"
#define costoP 300.00


float PREMIUM::CostoPremium = costoP;
PREMIUM::PREMIUM(int Edad, Paises Pais, string Password, const string Name, string tarjeta):
Usuarios(Edad, Pais, Password, Name)
{
	this->tarjeta = tarjeta;
	ListaDescargas = NULL;
	for (int i = 0; i < ListaDescargas->getTAM(); i++)
	{
		ListaDescargas[i] = NULL;
	}
}

PREMIUM::~PREMIUM(){
	delete ListaDescargas;//??
}





void PREMIUM::AumentarCalidad(){

}


void PREMIUM::DescargarAyV(Servicios* servicio){

}


void PREMIUM::Registrarse(){

}


