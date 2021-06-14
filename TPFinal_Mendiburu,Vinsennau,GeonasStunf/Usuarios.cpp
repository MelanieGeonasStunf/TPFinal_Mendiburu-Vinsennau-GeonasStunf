///////////////////////////////////////////////////////////
//  Usuarios.cpp
//  Implementation of the Class Usuarios
//  Created on:      01-Jun-2021 10:49:54 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Usuarios.h"
#include "Plataforma.h"
#include "PREMIUM.h"
#include "TipoUsuario.h"
#include "FREE.h"
#include "BASIC.h"

Usuarios::Usuarios(int Edad, Paises Pais, string Password, const string Name):UserName(Name)
{
	Estado = false;//usuario empieza desconectado o conectado?
	this->Pais = Pais;
	this->Password = Password;
	servicio = NULL;//no pasamos servicio?- lo seteamos despues?
	cantConexSemana = 0;
}

Usuarios::~Usuarios(){

}

void Usuarios::CerrarSesion(){
	if (!Estado)
		throw new exception("\nNunca debería pasar esto.");//vemos que hacemos
	Estado = false;
	setFHcierre();//vemos que hacemos
	RegUsuarios* regu = RegistrarenRegistro();
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
			setFHinicio();//le hacemos el local time?? 
			cListaT<RegUsuarios>* RegU = plataforma->getRgUsuarios();
			*RegU + RegistrarenRegistro();//hay que hacer la lista oublic o un get
			//no quiero programar mas por favor
			//plataforma->
			//
			cantConexSemana++;
			Casos2(this, plataforma);
		}
			
	}
}
//idea! Hcemos un local time de inicio de registro del susuario y despues par setear el final 
//le agregamos un rand entre 0,24 y 10 horas que sea equivalente al tiempo de conección del usuario. De esta forma 
//no nos va a quedar el mismo tiempo de inicio que final oalgo así, igual hay que hacer que llegue a pasar una semana
//sin que necesariamente pase


RegUsuarios* Usuarios::RegistrarenRegistro(){
	//hacemos un registro y en el constructor le pasamos por parametros a reg usuarios los datos del usuario
	RegUsuarios* reg;//CREO QUE TIENE QUE SER VIRTUAL PARA PODER PONER EL TIPO 
		
	
	if (dynamic_cast<PREMIUM*>(this)!= NULL )
	{
		reg = new RegUsuarios(UserName, premium);
	}
	if (dynamic_cast<BASIC*>(this) != NULL)
	{
		reg = new RegUsuarios(UserName, basic);
	}
	if (dynamic_cast<FREE*>(this) != NULL)
	{
		reg = new RegUsuarios(UserName, Free);
	}
	return reg;
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


