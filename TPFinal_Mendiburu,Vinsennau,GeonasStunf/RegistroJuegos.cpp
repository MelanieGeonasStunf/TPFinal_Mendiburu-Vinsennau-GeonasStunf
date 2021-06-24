#include "RegistroJuegos.h"



int RegistroJuegos::counter = 0;
RegistroJuegos::RegistroJuegos(const string Namecnst, string UserName, clave(to_string(counter)) :UserName(UserName),Nombre(Namecnst)
{
	counter++;
	CantidadPartidasGanadas = 0;//deberia estar?
	Fecha = { 0,0,0 };
	FechaUltimaJugada = { 0,0,0 };//Podriamos hacer un recuperar uletima partida
	Nivel=0;//aumenta en guardar progreso de juegos
	//no le tendriamos que pasar juegos?
}

RegistroJuegos::~RegistroJuegos(){

}