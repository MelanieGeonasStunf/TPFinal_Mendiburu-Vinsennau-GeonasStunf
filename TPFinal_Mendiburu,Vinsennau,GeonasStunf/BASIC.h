#pragma once

#include "Usuarios.h"
#include "Librerias.h"

class Plataforma;
class BASIC : public Usuarios
{
private:
	static float CostoBasic;//lo cambie a static
	//string tarjeta;
	bool calidad;

public:
	BASIC(int Edad, Paises Pais, string Password, const string Name, string tarjeta);
	virtual ~BASIC();
	BASIC(Usuarios& user);
	

	void Registrarse(Plataforma* plataforma);
	void setCalidad() { calidad = false; }
	void SeleccionarServicio(cListaT <Servicios>* serv);
	//elije un servicio de la lista de servicios


};
