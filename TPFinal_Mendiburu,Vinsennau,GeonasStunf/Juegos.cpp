#include "Juegos.h"
#include "RegistroJuegos.h"

Juegos::Juegos(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango, int NivelFinal)
	:Servicios(clave, nombre, cantP, paises, rango)
{
	this->NivelFinal = NivelFinal;
	Finalizado = false;
	tiempoInicio = { 0,0,0 };
	cantJugxPer = 0;
}

Juegos::Juegos(Juegos& juego) :Servicios(juego)
{
	NivelFinal=juego.NivelFinal;
	tiempoInicio = { 0,0,0 };
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
void Juegos::IniciarServicio()
{
	time_t rawtime;
	time(&rawtime);
	tm* hoy = localtime(&rawtime);
	tiempoInicio = *hoy;
}

RegistroJuegos* Juegos::RegistrarenRegistro(const string userName) 
{
	RegistroJuegos* reg = new RegistroJuegos(this->Nombre, userName);
	return reg;
}

ostream& Juegos::operator<<(ostream&out){
	 Servicios& P=*this;
	  out << &P;
	  out<< "\nNivel final: " << to_string(NivelFinal) << endl;
	  return out;
}