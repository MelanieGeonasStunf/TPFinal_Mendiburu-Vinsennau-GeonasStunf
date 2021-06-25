#pragma once

#include "Usuarios.h"

class Plataforma;
class FREE : public Usuarios
{
private:
	static int LimiteTiempoMax;

public:
	FREE(int Edad, Paises Pais, string Password, const string Name,string* tarjeta=NULL);
	virtual ~FREE();
	FREE(Usuarios& user);

	void Anuncios();//podemos ver si puede ser algun sonido

	void LimiteTiempo();
	//void SeleccionarServicio(cListaT<Servicios>*servicio);->era virtual
	void VariarLista();

	void Registrarse(Plataforma* plataforma);

};

