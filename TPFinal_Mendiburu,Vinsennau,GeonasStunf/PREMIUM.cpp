#include "PREMIUM.h"
#define costoP 300.00


float PREMIUM::CostoPremium = costoP;
PREMIUM::PREMIUM(int Edad, Paises Pais, string Password, const string Name, string tarjeta):
Usuarios(Edad, Pais, Password, Name)
{
	ListaDescargas = NULL;
	for (int i = 0; i < ListaDescargas->getTAM(); i++)
	{
		ListaDescargas[i] = NULL;
	}
}

PREMIUM::~PREMIUM(){
	delete ListaDescargas;//??
}


void PREMIUM::DescargarAyV(Servicios* servicio){
	*ListaDescargas + servicio;
}


void PREMIUM::Registrarse(Plataforma* plataforma){
	if (this == NULL)
		throw new exception("\nNo se pudo registrar el usuario ingresado.");
	if((plataforma->m_Usuarios->BuscarItem1(UserName))!=-1)
		throw new exception("\nEl nombre de usuario ingresado ya posee una cuenta" );//en este caso el usuario ya esta registrado
	*(plataforma->m_Usuarios) + this;
	Estado = true;//se inicia sesion
	setFHinicio();
	cListaT<RegUsuarios>* RegU = plataforma->getRgUsuarios();
	*RegU + RegistrarenRegistro();
	cantConexSemana++;
	
}
