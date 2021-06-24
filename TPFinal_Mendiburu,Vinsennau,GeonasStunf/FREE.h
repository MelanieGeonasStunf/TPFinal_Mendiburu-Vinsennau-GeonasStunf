#pragma once

#include "Usuarios.h"
#include "Librerias.h"

class FREE : public Usuarios
{
public:
	FREE(int Edad, Paises Pais, string Password, const string Name);
	virtual ~FREE();
	FREE(Usuarios& user);

	void Anuncios();//podemos ver si puede ser algun sonido

	void LimiteTiempo();
	//void SeleccionarServicio(cListaT<Servicios>*servicio);->era virtual
	void VariarLista();

	void Registrarse(Plataforma* plataforma);



private:
	static int LimiteTiempoMax;

};

