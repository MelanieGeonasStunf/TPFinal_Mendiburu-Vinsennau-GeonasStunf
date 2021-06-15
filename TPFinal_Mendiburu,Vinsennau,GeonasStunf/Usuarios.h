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
#include"TipoUsuario.h"

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
	Usuarios(Usuarios& user);

	void CerrarSesion();
	void IniciarSesion(Plataforma* plataforma);//llamamos a casos y a menu2 ->virtual?
	//tiene que verificar que la contrasena y el user sean correctos->verificar en m_Usuarios de plataforma

	RegUsuarios* RegistrarenRegistro();//plataforma usa el registro
	//friend? -> se supone que esta funcion la llama regUsuarios?

	virtual void Registrarse(Usuarios* user, Plataforma* plataforma);//->registra usuario!=iniciar sesion
	//tendria que ser virtual pura?-> esta en todos los hijos

	virtual void SeleccionarServicio(cListaT <Servicios> *servicio)=0;
	
	//getters y setters
	void setFHcierre(tm cierre);
	void setFHinicio(tm inicio);
	void setEliminado(bool elim);
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
