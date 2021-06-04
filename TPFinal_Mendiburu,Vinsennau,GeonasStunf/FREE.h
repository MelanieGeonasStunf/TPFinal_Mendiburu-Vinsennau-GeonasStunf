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
	FREE(int Edad, Paises Pais, string Password, const string Name);
	virtual ~FREE();

	void Anuncios();
	void LimiteTiempo();
	void Registrarse();
	void SeleccionarServicio(cListaT<Servicios>*servicio);
	void VariarLista();
	void EditarCuenta();

private:
	static int LimiteTiempoMax;

};

