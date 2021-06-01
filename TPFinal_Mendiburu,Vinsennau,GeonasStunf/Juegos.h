///////////////////////////////////////////////////////////
//  Juegos.h
//  Implementation of the Class Juegos
//  Created on:      01-Jun-2021 10:50:01 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Servicios.h"
#include "Librerias.h"

class Juegos : public Servicios
{
private:
	int NivelFinal;
	string NombreJuego;

public:
	Juegos(const string clave, tm duracion, const string nombre, Paises* paises);
	virtual ~Juegos();

	void GuardarProgreso();

};
