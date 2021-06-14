///////////////////////////////////////////////////////////
//  Plataforma.cpp
//  Implementation of the Class Plataforma
//  Created on:      01-Jun-2021 10:49:52 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Plataforma.h"
#include "FREE.h"
#include "BASIC.h"
#include "PREMIUM.h"

Plataforma::Plataforma():Nombre("Labfliz")
{
	this->CantidadUsuariosConectados=0;
	//ListaUsuariosxDia = new cListaT<Usuarios>;
	this-> UsuariosxSemana=0;
	m_Servicios=NULL;
	m_Usuarios=NULL;
	
	paises=new Paises[14]{Argentina, Chile,	Peru, Brasil, Colombia,	Mexico,	EstadosUnidos,
	Canada,Bolivia,	Paraguay,	Uruguay,	Venezuela,	España,	Francia};
}

Plataforma::~Plataforma(){
	//delete ListaUsuariosxDia;
	delete m_Usuarios;
	delete m_Servicios;
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



void Plataforma::PromedioConectadosenSemanaxDia()
{
}




void Plataforma::VerResumen(){

}

void Plataforma::EditarCuenta(Usuarios* user, int tipo, bool eliminar)
{	/*
	* 2 OPCIONES:
	* -Eliminar Cuenta.
	* -Cambiar tipo usuario.
	*/
	if (eliminar == true)
	{
		user->setEliminado(true);//=> se elimina al final de la semana para no tener problemas de memoria.
	}
	else//editamos la cuenta.
	{
		int t;//dependiendo el tipo del usuario es 0,1,2 (corresponde con el enum)
		if (dynamic_cast<FREE*>(user) != NULL)
		{
			t = 0;
		}
		if (dynamic_cast<FREE*>(user) != NULL)
		{
			t = 1;
		}
		if (dynamic_cast<FREE*>(user) != NULL)
		{
			t = 2;
		}
		if (tipo == Free && t!=0)
		{
			//hacemos funcion que copia al usuario y lo pasa a free
		}
		else if (tipo == basic && t!=1)
		{

		}
		else if (tipo == premium && t!=2)
		{

		}
		else
		{
			throw exception("Ese tipo no se encuentra disponible o ya sos el tipo de usuario:( ");//ya es de ese tipo
		}
	}
	//para mi: tiene que recibir el usuario y el tipo que se quiere cambiar
	//hacer enum con tipos de usuarios-> solo se puede elegir esas opciones
	

	//despues adentro si podemos hacer una funcion si queremos-> que haria igual?
	//comparamos el tipo que recibimos con todos los tipos hasta que sean iguales
	//si no hay ninguno igual -> throw que no se pudo editar nada-> si tenemos el enum haria falta?
	//si coincide con alguno: -> dynamic_cast para saber el tipo de usuario que era originalmente.
	//hacer copia del usuario y cambiar el tipo.->ni idea
}

