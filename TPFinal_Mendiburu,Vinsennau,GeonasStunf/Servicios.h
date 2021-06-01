///////////////////////////////////////////////////////////
//  Servicios.h
//  Implementation of the Class Servicios
//  Created on:      01-Jun-2021 10:49:56 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Usuarios.h"
#include "Librerias.h"

class Servicios
{

public:
	Servicios();
	virtual ~Servicios();
	Usuarios *m_Usuarios;

	void Apagar();
	void ChequearEdad();
	void Iniciar();
	void Pausar();
	void Reanudar();
	void VerificarPais();

private:
	const string Clave;
	tm duracion;
	const string Nombre;
	Paises* paises;
	int RegistrarenRegistro;

};

