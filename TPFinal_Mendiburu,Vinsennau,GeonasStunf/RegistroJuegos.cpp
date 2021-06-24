#include "RegistroJuegos.h"




RegistroJuegos::RegistroJuegos(const string Namecnst, string UserName) :UserName(UserName),Nombre(Namecnst)
{
	CantidadPartidasGanadas = 0;//deberia estar?
	Fecha = { 0,0,0 };
	FechaUltimaJugada = { 0,0,0 };//Podriamos hacer un recuperar uletima partida
	Nivel=0;//aumenta en guardar progreso de juegos
	//no le tendriamos que pasar juegos?

}

RegistroJuegos::~RegistroJuegos(){

}