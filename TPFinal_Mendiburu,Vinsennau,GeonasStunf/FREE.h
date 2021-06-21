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
	FREE(Usuarios& user);

	void Anuncios();//podemos ver si puede ser algun sonido

	void LimiteTiempo();
	//void SeleccionarServicio(cListaT<Servicios>*servicio);->era virtual
	void VariarLista();


private:
	static int LimiteTiempoMax;

};

