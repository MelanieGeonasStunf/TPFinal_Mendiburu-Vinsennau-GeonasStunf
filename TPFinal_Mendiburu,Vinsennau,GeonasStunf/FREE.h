#pragma once

#include "Usuarios.h"

class Plataforma;
class FREE : public Usuarios
{
private:
	static tm LimiteTiempoMax;
	long int tiempoConex;
	int contadorsem;//cant de conexiones
	//Servicios** ServAElegir;

public:
	FREE(int Edad, Paises Pais, string Password, const string Name,string* tarjeta=NULL);
	virtual ~FREE();
	FREE(Usuarios& user);

	void Anuncios();//podemos ver si puede ser algun sonido

	void LimiteTiempo();
	//void SeleccionarServicio(cListaT<Servicios>*servicio);->era virtual
	cListaT<Servicios>* VariarLista(cListaT<Servicios>* serv);

	void Registrarse(Plataforma* plataforma);
	void setCalidad()  { calidad  =  false;  }
	int getcontadorsem() { return contadorsem; }
	void setcontadorsem() {contadorsem++; }
	void SeleccionarServicio(cListaT <Servicios>* serv);
	void settiempoConex();
	void tiempoExcedido();
};

