///////////////////////////////////////////////////////////
//  RegUsuarios.h
//  Implementation of the Class RegUsuarios
//  Created on:      01-Jun-2021 10:50:22 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Usuarios.h"
#include "Librerias.h"

class RegUsuarios
{
private:
	tm Fecha;
	int TipoUsuario;
	const string UserName;

public:
	RegUsuarios(const string Name, int TipoUsuario);
	virtual ~RegUsuarios();
	
	void BuscarTipoUsuario();



};

