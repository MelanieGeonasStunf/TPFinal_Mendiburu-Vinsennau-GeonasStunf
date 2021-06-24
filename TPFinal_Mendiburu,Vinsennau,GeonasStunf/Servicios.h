#pragma once

#include "Librerias.h"
#include "Paises.h"
//#include "Plataforma.h" //INCLUI PLATAFORMA PQ SINO NO ME LO TOMABA, ESTA BIEN? O HAY QUE HACER CLASS PLATAFORMA?
class Plataforma;
enum RangoEtareo{nino, adolescente, adulto};
/*
* nino<13 anos
* adolescente<18
* adulto>18
*/
class Usuarios;

class Servicios
{
protected:
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
	void VerificarPais(Usuarios* user);


	void Apagar();
	virtual void IniciarServicio()=0;
	void Pausar();
	void Reanudar();

	string getclave()const { return Clave; };

	string getNombre()const { return Nombre; };
};

