///////////////////////////////////////////////////////////
//  Juegos.h
//  Implementation of the Class Juegos
//  Created on:      01-Jun-2021 10:50:01 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Servicios.h"
#include "Librerias.h"

class RegistroJuegos;

class Juegos : public Servicios
{
private:
	
	int NivelFinal;
	bool Finalizado;//completo todos los niveles?

	//string NombreJuego;->nombre ya esta en servicios

public:
	Juegos(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango, int NivelFinal);
	Juegos(Juegos& juego);
	virtual ~Juegos();

	RegistroJuegos* RegistrarenRegistro(string userName);
	void GuardarProgreso(RegistroJuegos* reg);
	void IniciarServicio();
	bool getEstado()  { return estado;  }; //estado de que?

};
