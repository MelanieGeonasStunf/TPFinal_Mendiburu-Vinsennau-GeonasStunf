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
	Reproduciendo = false;
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
	//system("pause");//se reanuda cuando aprieta enter-> y vuelve a contar el tiempo

}


void Servicios::Reanudar(){
	//reanuda el contador de tiempo
}


void Servicios::VerificarPais(Usuarios*user){
	
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


