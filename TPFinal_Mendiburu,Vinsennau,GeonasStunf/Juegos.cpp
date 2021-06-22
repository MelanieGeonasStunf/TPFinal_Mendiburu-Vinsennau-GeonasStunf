#include "Juegos.h"
#include "RegistroJuegos.h"

Juegos::Juegos(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango, int NivelFinal)
	:Servicios(clave, nombre, cantP, paises, rango)
{
	this->NivelFinal = NivelFinal;
	Finalizado = false;
}

Juegos::Juegos(Juegos& juego) :Servicios(juego)
{
NivelFinal=juego.NivelFinal;
Finalizado = juego.Finalizado;
}

Juegos::~Juegos(){

}

void Juegos::GuardarProgreso(RegistroJuegos* reg){
	int nro = rand() % 1; // si es 0: gano el nivel, si es 1: perdio el nivel
	if (nro == 0)
	{
		(reg->Nivel)++;
		if (NivelFinal == reg->Nivel) {
			Finalizado = true;
		}
	}
}
RegistroJuegos* Juegos::RegistrarenRegistro(const string userName){
	RegistroJuegos* reg = new RegistroJuegos(userName);//wtf  //jajajajaja no se
	return reg;

}