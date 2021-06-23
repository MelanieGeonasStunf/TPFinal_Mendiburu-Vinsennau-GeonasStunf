#include "FREE.h"


FREE::FREE(int Edad, Paises Pais, string Password, const string Name):
	Usuarios(Edad, Pais, Password, Name)
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