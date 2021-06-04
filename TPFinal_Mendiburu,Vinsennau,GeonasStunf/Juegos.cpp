///////////////////////////////////////////////////////////
//  Juegos.cpp
//  Implementation of the Class Juegos
//  Created on:      01-Jun-2021 10:50:02 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Juegos.h"

Juegos::Juegos(const string clave, const string nombre, Paises* paises, int NivelFinal)
	:Servicios(clave, nombre, paises)
{
	this->NivelFinal = NivelFinal;
}

Juegos::~Juegos(){

}





void Juegos::GuardarProgreso(){

}