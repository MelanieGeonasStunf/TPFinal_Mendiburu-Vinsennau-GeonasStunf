#include "Servicios.h"
#include "Usuarios.h"
#include "Plataforma.h"

Servicios::Servicios(const string clave,  const string nombre,int cantP, Paises* paises, RangoEtareo rango): 
	Clave(clave), Nombre(nombre)
{
	Reproduciendo = false;
	this->cantP = cantP;
	this->paises = paises;//no se si ta bien, el puntero que recibe deberia tener un array de paises almacenado
	rangoE = rango;
}

string Servicios::tostring()
{
	string cadena;
	cadena += "\nClave: " + Clave + "\nNombre: " + Nombre;
	return cadena;
}

Servicios::~Servicios(){

}





void Servicios::Apagar(){
	Reproduciendo = false;
}


int Servicios::ChequearEdad(){

	if (rangoE == nino)
		return 0;
	if (rangoE == adolescente)
		return 1;
	if (rangoE == adulto)
		return 2;
}



void Servicios::Pausar(){
	//system("pause");//se reanuda cuando aprieta enter-> y vuelve a contar el tiempo

}


void Servicios::Reanudar(){
	//reanuda el contador de tiempo
}


void Servicios::VerificarPais(Usuarios*user){
	
	for (int i = 0; i < cantP; i++)
	{
		if (user->getPais() == paises[i])
		{
			return;
		}
	}
	//si llega aca significa que el servicio no esta disponible en el pais del usuario
	throw exception("Servicio no disponible :(");
}


