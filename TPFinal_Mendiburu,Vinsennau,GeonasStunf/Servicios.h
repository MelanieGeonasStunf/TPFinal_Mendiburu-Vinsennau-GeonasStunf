///////////////////////////////////////////////////////////
//  Servicios.h
//  Implementation of the Class Servicios
//  Created on:      01-Jun-2021 10:49:56 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Librerias.h"
#include "Paises.h"

class Servicios
{
private:
	const string Clave;
	//tm duracion;
	const string Nombre;
	Paises* paises;	

public:
	Servicios(const string clave, const string nombre, Paises* paises);
	virtual ~Servicios();

	void Apagar();
	void ChequearEdad();
	void Iniciar();
	void Pausar();
	void Reanudar();
	void VerificarPais();
	void RegistrarenRegistro(Servicios* servicio);
};

