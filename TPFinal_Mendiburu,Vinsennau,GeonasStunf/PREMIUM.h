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

public:
	PREMIUM(int Edad, Paises Pais, string Password, const string Name);
	virtual ~PREMIUM();

	void AumentarCalidad();
	void DescargarAyV(Servicios* servicio);
	void Registrarse();
	void SeleccionarServicio(cListaT <Servicios>* servicio);

private:
	int CostoPremium;
	cListaT <Servicios>* ListaDescargas;
};
