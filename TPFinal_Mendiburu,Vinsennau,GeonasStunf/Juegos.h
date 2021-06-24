#pragma once

#include "Servicios.h"
#include "Librerias.h"

class RegistroJuegos;

class Juegos : public Servicios
{
private:
	
	int NivelFinal;
	bool Finalizado;//completo todos los niveles?
	int cantJugxPer;
	//string NombreJuego;->nombre ya esta en servicios

public:
	Juegos(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango, int NivelFinal);
	Juegos(Juegos& juego);
	virtual ~Juegos();

	RegistroJuegos* RegistrarenRegistro(string userName);
	void GuardarProgreso(RegistroJuegos* reg);
	void IniciarServicio();//que haria?
	bool getEstado()  { return this->Finalizado;  }; //estado de que?
	void setCont() { cantJugxPer++; }
	int getCont() { return cantJugxPer; }
};
