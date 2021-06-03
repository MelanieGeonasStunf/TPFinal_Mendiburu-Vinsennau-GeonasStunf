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

class Plataforma
{
private:
	int CantidadUsuariosConectados;
	cListaT <Usuarios>* ListaUsuariosxDia;
	const string Nombre;
	int UsuariosxSemana;
	cListaT <Usuarios>* m_Usuarios;
	//AGREGADO:
	Paises* paises;

public:
	cListaT <Servicios>* m_Servicios;

	Plataforma();
	virtual ~Plataforma();

	void EstadisticasPorContenido();
	cListaT <Audio> *MasEscuchados(tm Periodo);
	cListaT <Juegos> *MasJugados(tm Periodo);
	cListaT <AudioVisual> *MasVistos(tm Periodo);
	void PromedioConectadosDia();
	void PromedioConectadosSemana();
	void VerResumen ();//da resumen de la semana


	
};

