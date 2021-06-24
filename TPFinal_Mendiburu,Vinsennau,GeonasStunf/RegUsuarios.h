#pragma once


#include "Librerias.h"

class RegUsuarios
{
private:
	tm Fecha;
	int TipoUsuario;
	const string UserName;
	//no tendria que haber lista de usuarios?
public:
	RegUsuarios(const string Name, int TipoUsuario);
	virtual ~RegUsuarios();
	
	void BuscarTipoUsuario();
	//setear fecha aparte

};

