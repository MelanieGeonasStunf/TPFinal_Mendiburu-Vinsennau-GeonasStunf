///////////////////////////////////////////////////////////
//  Usuarios.h
//  Implementation of the Class Usuarios
//  Created on:      01-Jun-2021 10:49:54 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Librerias.h"
#include "Paises.h"

class Usuarios
{

public:
	Usuarios();
	virtual ~Usuarios();

	void CerrarSesion();
	void IniciarSesion();
	void RegistrarenRegistro();
	virtual void Registrarse();
	virtual void SeleccionarServicio();

private:
	int Edad;
	bool Estado;
	tm FechayHoraCierre;
	tm FechayHoraInicio;
	Paises Pais;
	string Password;
	const string UserName;

};
