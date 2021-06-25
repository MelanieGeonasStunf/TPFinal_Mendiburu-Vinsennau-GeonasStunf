#pragma once

#include "Usuarios.h"
#include "Servicios.h"
//#include "Librerias.h"
#include "cListaT.h"

class PREMIUM : public Usuarios
{
private:
	static float CostoPremium;
	cListaT <Servicios>* ListaDescargas;
	string tarjeta;
	
public:
	PREMIUM(int Edad, Paises Pais, string Password, const string Name, string* tarjeta);
	PREMIUM(Usuarios& copia);
	virtual ~PREMIUM();

	void Registrarse( Plataforma* plataforma);
	void DescargarAyV(Servicios* servicio);
	ostream& operator<<(ostream& out);
	void setCalidad() { calidad = true; }
	void SeleccionarServicio(cListaT <Servicios> *serv);
	//string tostring();

	//void SeleccionarServicio(cListaT <Servicios>* servicio);
};
