///////////////////////////////////////////////////////////
//  FREE.h
//  Implementation of the Class FREE
//  Created on:      01-Jun-2021 10:49:57 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Usuarios.h"
#include "Librerias.h"

class FREE : public Usuarios
{

public:
	FREE();
	virtual ~FREE();

	void Anuncios();
	void LimiteTiempo();
	void Registrarse();
	void SeleccionarServicio();
	void VariarLista();

private:
	static int LimiteTiempoMax;

};

