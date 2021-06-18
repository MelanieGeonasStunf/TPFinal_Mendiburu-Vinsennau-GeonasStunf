///////////////////////////////////////////////////////////
//  Servicios.h
//  Implementation of the Class Servicios
//  Created on:      01-Jun-2021 10:49:56 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#pragma once

#include "Librerias.h"
#include "Paises.h"

enum RangoEtareo{nino, adolescente, adulto};
/*
* nino<13 anos
* adolescente<18
* adulto>18
*/
class Usuarios;
class Servicios
{
private:
	friend void ReproducirServicio(Usuarios* user, Plataforma* plataforma);
	const string Clave;
	//tm duracion;
	const string Nombre;
	Paises* paises;	
	int cantP;
	RangoEtareo rangoE;
	//poner hora inicio
	bool Reproduciendo;//true se esta reproduciendo

public:
	Servicios(const string clave, const string nombre,int cantP, Paises* paises, RangoEtareo rango);
	Servicios(Servicios& copia) :Clave(copia.Clave), Nombre(copia.Nombre), cantP(copia.cantP), rangoE(copia.rangoE){};
	virtual ~Servicios();

	
	int ChequearEdad();
	void VerificarPais(Usuarios* user);//


	void Apagar();
	virtual void IniciarServicio()=0;
	void Pausar();
	void Reanudar();
	/*Podemos hacer como un "menu"->
	* si toca " ": inicia un texto.
	* si toca " " y ya se inicio: pausa
	* si toca " ": cuando estaba en pausa: reinicia
	* si toca "b": se apaga (de bye)
	*/

};

