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
	//le tendriamos que poner algun atributo?
public:
	FREE(int Edad, Paises Pais, string Password, const string Name);
	virtual ~FREE();
	FREE(Usuarios& user);

	void Anuncios();
	void LimiteTiempo();//cada 10 min llama a anuncios (o menos tiempo para no esperar 10 min)
	void Registrarse();
	//void SeleccionarServicio(cListaT<Servicios>*servicio);->era virtual
	void VariarLista();


private:
	static int LimiteTiempoMax;

};

