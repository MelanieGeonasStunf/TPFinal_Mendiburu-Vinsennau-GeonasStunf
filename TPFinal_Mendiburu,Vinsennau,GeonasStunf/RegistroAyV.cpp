#include "RegistroAyV.h"
#include "funciones.cpp"


int RegistroAyV::counter = 0;
RegistroAyV::RegistroAyV(string nom, const string Name, bool visto) :UserName(Name), clave(to_string(counter))
{
	counter++;
	Fecha = setLocalTime();
	//tm tiempoReproduccion;
	Visto=visto;//vio + 30% ->lo vio
	Nombre = nom;
}

RegistroAyV::~RegistroAyV(){

}