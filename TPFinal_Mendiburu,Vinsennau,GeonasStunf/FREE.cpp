///////////////////////////////////////////////////////////
//  FREE.cpp
//  Implementation of the Class FREE
//  Created on:      01-Jun-2021 10:49:57 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "FREE.h"


FREE::FREE(int Edad, Paises Pais, string Password, const string Name):
	Usuarios(Edad, Pais, Password, Name)
{

}



FREE::~FREE(){

}

FREE::FREE(Usuarios& user):Usuarios(user)
{
}





void FREE::Anuncios(){

}


void FREE::LimiteTiempo(){

}


void FREE::Registrarse(){

}

void FREE::SeleccionarServicio(cListaT<Servicios>* servicio)
{
}

void FREE::VariarLista(){

}