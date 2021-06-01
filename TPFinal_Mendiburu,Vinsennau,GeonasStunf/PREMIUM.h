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

class PREMIUM : public Usuarios
{

public:
	PREMIUM();
	virtual ~PREMIUM();
	Servicios *m_Servicios;

	void AumentarCalidad();
	void DescargarAyV(Servicios* servicio);
	void Registrarse();
	void SeleccionarServicio(Servicios* servicio);

private:
	int CostoPremium;

};
