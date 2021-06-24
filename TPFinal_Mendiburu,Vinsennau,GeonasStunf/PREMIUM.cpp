#include "PREMIUM.h"
#define costoP 300.00


float PREMIUM::CostoPremium = costoP;
PREMIUM::PREMIUM(int Edad, Paises Pais, string Password, const string Name, string tarjeta):
Usuarios(Edad, Pais, Password, Name)
{
	this->tarjeta = tarjeta;
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

istream& PREMIUM::operator>>(istream& in){
	cout << "\nIngrese el numero de la tarjeta: " << endl;
	int numero;  
	in >> numero;
	return in;
}



