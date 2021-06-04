///////////////////////////////////////////////////////////
//  Usuarios.h
//  Implementation of the Class Usuarios
//  Created on:      01-Jun-2021 10:49:54 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Librerias.h"
#include "Paises.h"
#include "Servicios.h"
#include "cListaT.h"

class Plataforma;

class Usuarios
{

private:
	int Edad;
	bool Estado;
	tm FechayHoraCierre;
	tm FechayHoraInicio;
	Paises Pais;
	string Password;
	const string UserName;
	Servicios* servicio;

public:
	Usuarios(int Edad, Paises Pais,string Password, const string Name);
	virtual ~Usuarios();

	void CerrarSesion();
	void IniciarSesion(Plataforma* plataforma);//llamamos a casos y a menu2
	void RegistrarenRegistro();
	virtual void Registrarse();//verifica que contrasena sea correcta
	virtual void SeleccionarServicio(cListaT <Servicios> *servicio);
	virtual void EditarCuenta()=0;// cambia de free a premium por ejemplo
	//AGREGADO:
	bool VerificarContrasena();//verifica que cumpla requisitos
	/*
	* REQUISITOS:
	* - +8 caracteres
	* - Mayuscula
	* - Numero
	* - Simbolo
	* - Sin espacios
	*/
};
