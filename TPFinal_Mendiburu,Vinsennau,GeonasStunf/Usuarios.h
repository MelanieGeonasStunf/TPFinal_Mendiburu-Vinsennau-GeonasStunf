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
#include "RegUsuarios.h"
#include "funciones.h"

class Plataforma;
class PREMIUM;
class BASIC;
class FREE;

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
	Servicios* servicio;//servicio que esta usando el usuario en el momento.
	int cantConexSemana;
	bool Eliminado;//
	//si es true-> iniciar sesion ->no puede iniciar
	//termina la semana-> en el main nos fijamos que usuarios estan en true y los eliminamos (delete)
	//si es false-> no pasa nada
public:
	Usuarios(int Edad, Paises Pais,string Password, const string Name);
	virtual ~Usuarios();

	void CerrarSesion();
	void IniciarSesion(Plataforma* plataforma);//llamamos a casos y a menu2 ->virtual?

	RegUsuarios* RegistrarenRegistro();//plataforma usa el registro
	//friend? -> se supone que esta funcion la llama regUsuarios?

	virtual void Registrarse();//verifica que contrasena sea correcta->registra usuario!=iniciar sesion
	//tendria que ser virtual pura?-> esta en todos los hijos

	virtual void SeleccionarServicio(cListaT <Servicios> *servicio)=0;
	
	//getters y setters
	void setFHcierre(tm cierre);
	void setFHinicio(tm inicio);

	//AGREGADO:
	bool VerificarContrasena();//verifica que cumpla requisitos-> ya hecha!
	/*
	* REQUISITOS:
	* - +8 caracteres
	* - Mayuscula
	* - Numero
	* - Simbolo
	* - Sin espacios
	*/
};
