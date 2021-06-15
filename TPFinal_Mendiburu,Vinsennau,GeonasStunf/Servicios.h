///////////////////////////////////////////////////////////
//  Servicios.h
//  Implementation of the Class Servicios
//  Created on:      01-Jun-2021 10:49:56 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Librerias.h"
#include "Paises.h"

class Usuarios;
class Servicios
{
private:
	const string Clave;
	//tm duracion;
	const string Nombre;
	Paises* paises;	
	int cantP;

public:
	Servicios(const string clave, const string nombre,int cantP, Paises* paises);
	virtual ~Servicios();

	void Apagar();
	void ChequearEdad();
	/*Podemos hacer como un "menu"->
	* si toca " ": inicia un texto.
	* si toca " " y ya se inicio: pausa
	* si toca " ": cuando estaba en pausa: reinicia
	* si toca "b": se apaga (de bye)
	*/
	void Iniciar();
	void Pausar();
	void Reanudar();
	void VerificarPais(Usuarios*user);//


	//void RegistrarenRegistro(Servicios* servicio);//?
	//
};

