#include "BASIC.h"
#define CostoB 200.00//defino costo basic

float BASIC::CostoBasic = CostoB;
BASIC::BASIC(int Edad, Paises Pais, string Password, const string Name, string tarjeta):
	Usuarios(Edad, Pais, Password, Name)
{
	this->tarjeta = tarjeta;
}

BASIC::~BASIC(){

}

BASIC::BASIC(Usuarios& user, string tarjeta):Usuarios(user)
{
	this->tarjeta = tarjeta;
}


void BASIC::Registrarse(Plataforma* plataforma)
{
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






