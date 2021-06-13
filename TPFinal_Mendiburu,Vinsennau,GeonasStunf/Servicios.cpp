///////////////////////////////////////////////////////////
//  Servicios.cpp
//  Implementation of the Class Servicios
//  Created on:      01-Jun-2021 10:49:56 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Servicios.h"


Servicios::Servicios(const string clave,  const string nombre, Paises* paises): 
	Clave(clave), Nombre(nombre)
{
	this->paises = paises;
}



Servicios::~Servicios(){

}





void Servicios::Apagar(){

}


void Servicios::ChequearEdad(){

}


void Servicios::Iniciar(){

}


void Servicios::Pausar(){

}


void Servicios::Reanudar(){

}


void Servicios::VerificarPais(){

}


