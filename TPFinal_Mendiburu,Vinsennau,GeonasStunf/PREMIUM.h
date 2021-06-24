#pragma once

#include "Usuarios.h"
#include "Servicios.h"
#include "Librerias.h"
#include "cListaT.h"

class PREMIUM : public Usuarios
{
private:
	static float CostoPremium;
	cListaT <Servicios>* ListaDescargas;
	string tarjeta;
	
public:
	PREMIUM(int Edad, Paises Pais, string Password, const string Name, string tarjeta="");
	virtual ~PREMIUM();

	void DescargarAyV(Servicios* servicio);
	//void SeleccionarServicio(cListaT <Servicios>* servicio);
	void setTarjeta() { cin >> tarjeta; }//confiamos en meli 
	istream& operator>>(istream& in);
};
