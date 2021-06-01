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

class Plataforma
{

public:
	Plataforma();
	virtual ~Plataforma();
	Servicios *m_Servicios;
	Usuarios *m_Usuarios;

	void EstadisticasPorContenido();
	Audio** MasEscuchados(tm Periodo);
	Juegos** MasJugados(tm Periodo);
	AudioVisual** MasVistos(tm Periodo);
	void PromedioConectadosDia();
	void PromedioConectadosSemana();
	void VerResumen(tm Periodo);

private:
	int CantidadUsuariosConectados;
	Usuarios** ListaUsuariosxDia;
	const string Nombre;
	int UsuariosxSemana;

};

