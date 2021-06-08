///////////////////////////////////////////////////////////
//  PREMIUM.h
//  Implementation of the Class PREMIUM
//  Created on:      01-Jun-2021 10:50:00 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Usuarios.h"
#include "Servicios.h"
#include "Librerias.h"
#include "cListaT.h"

class PREMIUM : public Usuarios
{
private:
	static float CostoPremium;
	cListaT <Servicios>* ListaDescargas;
	string tarjeta;
	
public:
	PREMIUM(int Edad, Paises Pais, string Password, const string Name, string tarjeta);
	virtual ~PREMIUM();

	void AumentarCalidad();
	void DescargarAyV(Servicios* servicio);
	void Registrarse();
	void SeleccionarServicio(cListaT <Servicios>* servicio);
	void EditarCuenta();
};
