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
private:
	friend class Juegos;
	int CantidadPartidasGanadas;
	tm Fecha;
	tm FechaUltimaJugada;
	int Nivel;//aumenta en guardar progreso de juegos
	const string UserName;
	//no le tendriamos que pasar juegos?

public:
	RegistroJuegos(const string Namecnst ,string UserName);
	virtual ~RegistroJuegos();
};

