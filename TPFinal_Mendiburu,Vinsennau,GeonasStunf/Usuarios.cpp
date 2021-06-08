///////////////////////////////////////////////////////////
//  Usuarios.cpp
//  Implementation of the Class Usuarios
//  Created on:      01-Jun-2021 10:49:54 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Usuarios.h"
#include "Plataforma.h"


Usuarios::Usuarios(int Edad, Paises Pais, string Password, const string Name):UserName(Name)
{
	Estado = false;//usuario empieza desconectado o conectado?
	this->Pais = Pais;
	this->Password = Password;
	servicio = NULL;//no pasamos servicio?- lo seteamos despues?
}

Usuarios::~Usuarios(){

}





void Usuarios::CerrarSesion(){

}


void Usuarios::IniciarSesion(Plataforma* plataforma){
	//Llamamos a Menu2 y Casos2
	int pos = -1;
	if (plataforma != NULL)
	{
		try
		{
			pos = plataforma->m_Usuarios->BuscarItem1(UserName);
		}
		catch (exception& e)
		{
			throw e.what();
		}
		
		if (plataforma->m_Usuarios->vector[pos]->Password == Password)
		{
			Estado = true;//se inicia sesion
			//plataforma->
			//
		}
			
	}
}


RegUsuarios* Usuarios::RegistrarenRegistro(){
	//hacemos un registro y en el constructor le pasamos por parametros a reg usuarios los datos del usuario
}


void Usuarios::Registrarse(){

}

void Usuarios::SeleccionarServicio(cListaT<Servicios>* servicio)
{
}

bool Usuarios::VerificarContrasena()
{
	/*
	* REQUISITOS:
	* - +8 caracteres
	* - Mayuscula
	* - Numero
	* - Simbolo-> sin ; , : . " ' 
	* - Sin espacios
	*/

	if (Password.length() > 8 && Password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos
		&& Password.find_first_of("123456789") != string::npos && Password.find_first_of("~!@#$%^&*()<>?/\[]{}*+-_=") != string::npos &&
		Password.find_first_of(" ") == string::npos)
	{
		return true;
	}
		
	return false;
}


