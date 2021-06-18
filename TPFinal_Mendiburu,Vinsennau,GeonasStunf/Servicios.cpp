///////////////////////////////////////////////////////////
//  Servicios.cpp
//  Implementation of the Class Servicios
//  Created on:      01-Jun-2021 10:49:56 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Servicios.h"
#include "Usuarios.h"

Servicios::Servicios(const string clave,  const string nombre,int cantP, Paises* paises, RangoEtareo rango): 
	Clave(clave), Nombre(nombre)
{
	this->cantP = cantP;
	this->paises[cantP] = paises[cantP];//no se si ta bien
	rangoE = rango;
}



Servicios::~Servicios(){

}





void Servicios::Apagar(){

}


int Servicios::ChequearEdad(){

	if (rangoE == nino)
		return 0;
	if (rangoE == adolescente)
		return 1;
	if (rangoE == adulto)
		return 2;
	//== return rangoE;
}



void Servicios::Pausar(){

}


void Servicios::Reanudar(){
	
}


void Servicios::VerificarPais(Usuarios*user){
	/*
	usuario tiene servicio=>
	usuario*pepito=new us (..., servicio*,...)
	=>En seleccionarservicio-> servicio->verificarpais();
	=>verificarpais()
	{if(user->pais == pais[i])-> for recorre lista paises
	puede tener servicio
	if(i=n paises)
	no puede tener servicio->throw
	}

	*/
	for (int i = 0; i < cantP; i++)
	{
		if (user->getPais() == paises[i])
		{
			return;
		}
	}
	//si llega aca significa que el servicio no esta disponible en el pais del usuario
	throw exception("Servicio no disponible :(");
}


