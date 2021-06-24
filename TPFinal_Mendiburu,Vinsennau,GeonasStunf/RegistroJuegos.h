#pragma once

#include "Juegos.h"
#include "Librerias.h"

class RegistroJuegos
{
private:
	friend class Juegos;
	string Nombre;
	int CantidadPartidasGanadas;
	const string clave;
	//tm Fecha;
	tm FechaUltimaJugada;
	int Nivel;//aumenta en guardar progreso de juegos
	const string UserName;
	static int counter;
	//no le tendriamos que pasar juegos?

public:
	RegistroJuegos(const string Namecnst ,string UserName);
	virtual ~RegistroJuegos();

	tm getFechaUltJ() { return FechaUltimaJugada; }
	string getNombre() { return Nombre; }
};

