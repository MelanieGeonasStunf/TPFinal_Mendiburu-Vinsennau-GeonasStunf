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

public:
	RegUsuarios();
	virtual ~RegUsuarios();
	Usuarios *m_Usuarios;

	void BuscarTipoUsuario();

private:
	tm Fecha;
	int TipoUsuario;
	int UserName;

};

