   ///////////////////////////////////////////////////////////
//  Plataforma.h
//  Implementation of the Class Plataforma
//  Created on:      01-Jun-2021 10:49:51 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Servicios.h"
#include "Usuarios.h"
#include "Librerias.h"
#include "Juegos.h"
#include "Audio.h"
#include "AudioVisual.h"
#include "cListaT.h"
#include "RegUsuarios.h"
#include "RegistroAyV.h"
#include "RegistroJuegos.h"

class FREE;
class BASIC;
class PREMIUM;

class Plataforma
{
private:
	int CantidadUsuariosConectados;
	
	//cListaT <Usuarios>* ListaUsuariosxDia;
	const string Nombre;
	int UsuariosxSemana;
	
	cListaT<RegUsuarios>* RegU;
	cListaT<RegistroJuegos>* RegJ;
	cListaT<RegistroAyV>* RegAyV;

	//AGREGADO:
	Paises* paises;

public:
	cListaT <Servicios>* m_Servicios;
	cListaT <Usuarios>* m_Usuarios;

	Plataforma();
	virtual ~Plataforma();

	void EstadisticasPorContenido();
	cListaT <Audio> *MasEscuchados(tm Periodo);
	cListaT <Juegos> *MasJugados(tm Periodo);
	cListaT <AudioVisual> *MasVistos(tm Periodo);
	//Periodo->pasar dos fechas o que te devuelva unicamente lo de la ultima semana.

	void PromedioConectadosenSemanaxDia();
	
	void VerResumen ();//da resumen de la semana

	//Usuarios* get
	void EditarCuenta(Usuarios*user, int tipo, bool eliminar);//no me toma el enum!
	//THROW!!!!
	//void CambiarTipo(Usuarios* user, int tipo);
	// 
	// 
	//eliminar-> true: elimina usuario (el tipo recibido es el original), false-> cambia el tipo
	/*
	* 2 OPCIONES:
	* -Eliminar Cuenta.
	* -Cambiar tipo usuario.
	*/
	//para mi: tiene que recibir el usuario y el tipo que se quiere cambiar
	//hacer enum con tipos de usuarios-> solo se puede elegir esas opciones
	//tendria que ser global o ir solo en usuario (no virtual)
	//el usuario que queremos cambiar es el que llama a la funicion y es el mismo que recibe por parametro
	//despues adentro si podemos hacer una funcion si queremos-> que haria igual?
	//comparamos el tipo que recibimos con todos los tipos hasta que sean iguales
	//si no hay ninguno igual -> throw que no se pudo editar nada-> si tenemos el enum haria falta?
	//si coincide con alguno: -> dynamic_cast para saber el tipo de usuario que era originalmente.
	//hacer copia del usuario y cambiar el tipo.->ni idea
	
	//seters y geters
	cListaT<RegUsuarios>* getRgUsuarios() { return RegU; }
	cListaT<RegistroAyV>* getRgAyV() { return RegAyV; }
};

