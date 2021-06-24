#include "FREE.h"


FREE::FREE(int Edad, Paises Pais, string Password, const string Name,string* tarjeta):
	Usuarios(Edad, Pais, Password, Name,tarjeta)
{

}



FREE::~FREE(){

}

FREE::FREE(Usuarios& user):Usuarios(user)
{
}





void FREE::Anuncios(){
//imprimimos algo en la pantalla?
}


void FREE::LimiteTiempo(){
	//hacer contador que limite el tiempo -> por dia?/hora?/...
}



void FREE::VariarLista(){

}


void FREE::Registrarse(Plataforma* plataforma){
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