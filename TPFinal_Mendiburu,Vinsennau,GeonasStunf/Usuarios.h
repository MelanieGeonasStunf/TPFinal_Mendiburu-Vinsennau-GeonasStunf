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
#include "TipoUsuario.h"
//#include "cListaT.h"

class Plataforma;
class PREMIUM;
class BASIC;
class FREE;
class Audiovisual;
class Audio;

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
	friend void ReproducirServicio(Usuarios* user, Plataforma* plataforma);
	bool Eliminado;////si es true-> iniciar sesion ->no puede iniciar
	//termina la semana-> en el main nos fijamos que usuarios estan en true y los eliminamos (delete)
	//si es false-> no pasa nada

	//int tiempoconex;->cuenta el tiempo de conexion del usuario que nos va a servir para setear el horario
	//del cierre de sesion y para limitar a los usuarios FREE.
	cListaT<AudioVisual>* ListadeRecientesAyV;
	cListaT <Audio>* ListaRecientesA;//tenia doble puntero y le saque uno

	
public:
	Usuarios(int Edad, Paises Pais,string Password, const string Name);
	virtual ~Usuarios();
	Usuarios(Usuarios& user);

	void CerrarSesion();
	void IniciarSesion(Plataforma* plataforma);//llamamos a casos y a menu2 ->virtual?
	//tiene que verificar que la contrasena y el user sean correctos->verificar en m_Usuarios de plataforma

	RegUsuarios* RegistrarenRegistro();//plataforma usa el registro
	void Registrarse(Usuarios* user, Plataforma* plataforma);//->registra usuario!=iniciar sesion
	//tendria que ser virtual pura?-> esta en todos los hijos

	void SeleccionarServicio(cListaT <Servicios> *serv);
	/*se fija si el servicio que esta en la lista que le paso por parametro
	*/
	//hay alguna restriccion con free/premium?
	
	//getters y setters
	void setFHcierre(tm cierre);
	void setFHinicio(tm inicio);//PROBLEMA!!
	void setEliminado(bool elim);
	string getUserName() { return UserName; };
	tm getFechayHoraCierre() { return FechayHoraCierre; };

	Paises getPais();

	//AGREGADO:
	bool VerificarContrasena();//verifica que cumpla requisitos-> ya hecha!
	
};
