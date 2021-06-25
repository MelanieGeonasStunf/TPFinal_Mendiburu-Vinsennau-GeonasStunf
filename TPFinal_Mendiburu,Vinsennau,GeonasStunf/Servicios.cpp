#include "Servicios.h"
#include "Usuarios.h"
#include "Plataforma.h"

Servicios::Servicios(const string clave,  const string nombre,int cantP, Paises* paises_, RangoEtareo rango): 
	Clave(clave), Nombre(nombre)
{
	Reproduciendo = false;
	this->cantP = cantP;
	paises = new Paises[cantP];

	for (int i = 0; i < cantP; i++) {
		paises[i] = paises_[i];//no se si ta bien, el puntero que recibe deberia tener un array de paises almacenado
	}
	rangoE = rango;
}

Servicios::Servicios(Servicios& copia): Clave(copia.Clave), Nombre(copia.Nombre), cantP(copia.cantP), rangoE(copia.rangoE)
{
	Reproduciendo = false;
	this->cantP = copia.cantP;
	paises = new Paises[cantP];

	for (int i = 0; i < cantP; i++) {
		paises[i] = copia.paises[i];//no se si ta bien, el puntero que recibe deberia tener un array de paises almacenado
	}
	rangoE = copia.rangoE;
}

string Servicios::tostring()
{
	string cadena;
	cadena+= "\nClave: " + Clave + "\nNombre: " + Nombre +'\n';
	return cadena;
}

ostream& Servicios::operator<<(ostream& out)
{
	
	out << "\nClave: " << Clave << "\nNombre: " << Nombre << endl;
	return out;
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
	system("pause");//se reanuda cuando aprieta enter-> y vuelve a contar el tiempo
	cout << "\Reproduccion: " << Nombre << " pausada."<<endl;
}


void Servicios::Reanudar(){
	//reanuda el contador de tiempo
	cout << "\Reanudando " << Nombre << endl;
}


void Servicios::VerificarPais(Usuarios*user){
	
	for (int i = 0; i < cantP; i++)
	{
		if (this != NULL) {
			if (user->getPais() == paises[i])
			{
				return;
			}
		}
	}
	//si llega aca significa que el servicio no esta disponible en el pais del usuario
	throw new exception("Servicio no disponible :(");
}


