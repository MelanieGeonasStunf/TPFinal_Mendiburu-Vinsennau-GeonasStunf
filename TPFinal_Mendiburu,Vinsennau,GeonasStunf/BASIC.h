///////////////////////////////////////////////////////////
//  BASIC.h
//  Implementation of the Class BASIC
//  Created on:      01-Jun-2021 10:49:59 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Usuarios.h"
#include "Librerias.h"

class BASIC : public Usuarios
{

public:
	BASIC();
	virtual ~BASIC();

	void Registrarse();
	void SeleccionarServicio();

private:
	int CostoBasic;

};
