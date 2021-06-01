///////////////////////////////////////////////////////////
//  Plataforma.cpp
//  Implementation of the Class Plataforma
//  Created on:      01-Jun-2021 10:49:52 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Plataforma.h"


Plataforma::Plataforma():Nombre("Labfliz")
{
	/*this->CantidadUsuariosConectados=0;
	ListaUsuariosxDia = new cListaT<Usuarios>;
	this-> UsuariosxSemana=0;
	m_Servicios=NULL;
	m_Usuarios=NULL;*/
}

Plataforma::~Plataforma(){
	//delete ListaUsuariosxDia;
}


void Plataforma::EstadisticasPorContenido(){

}


cListaT<Audio>* Plataforma::MasEscuchados(tm Periodo){

	return  NULL;
}


cListaT<Juegos>* Plataforma::MasJugados(tm Periodo){

	return  NULL;
}


cListaT<AudioVisual>* Plataforma::MasVistos(tm Periodo){

	return  NULL;
}


void Plataforma::PromedioConectadosDia(){

}


void Plataforma::PromedioConectadosSemana(){

}


void Plataforma::VerResumen(tm Periodo){

}