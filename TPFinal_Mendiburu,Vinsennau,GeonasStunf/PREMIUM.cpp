///////////////////////////////////////////////////////////
//  PREMIUM.cpp
//  Implementation of the Class PREMIUM
//  Created on:      01-Jun-2021 10:50:00 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "PREMIUM.h"
#define costoP 300.00


PREMIUM::PREMIUM(int Edad, Paises Pais, string Password, const string Name, string tarjeta):
Usuarios(Edad, Pais, Password, Name)
{
	this->tarjeta = tarjeta;
	CostoPremium = costoP;
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

void PREMIUM::SeleccionarServicio(cListaT<Servicios>* servicio)
{
}
