///////////////////////////////////////////////////////////
//  RegistroJuegos.h
//  Implementation of the Class RegistroJuegos
//  Created on:      01-Jun-2021 10:50:19 AM
//  Original author: gstun
#pragma once

#include "Juegos.h"
#include "Librerias.h"

class RegistroJuegos
{

public:
	RegistroJuegos();
	virtual ~RegistroJuegos();
	Juegos *m_Juegos;

private:
	int CantidadPartidasGanadas;
	tm Fecha;
	tm FechaUltimaJugada;
	int Nivel;
	const string UserName;

};

