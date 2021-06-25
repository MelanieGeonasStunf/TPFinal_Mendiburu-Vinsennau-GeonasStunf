#include "PREMIUM.h"
#define costoP 300.00
#include "Plataforma.h"


float PREMIUM::CostoPremium = costoP;
PREMIUM::PREMIUM(int Edad, Paises Pais, string Password, const string Name, string tarjeta):
Usuarios(Edad, Pais, Password, Name)
{
	calidad = true;
	ListaDescargas = new cListaT<Servicios>(10);
	for (int i = 0; i < ListaDescargas->getTAM(); i++)
	{
		ListaDescargas[i] = NULL;
	}
}

PREMIUM::PREMIUM(Usuarios& copia):Usuarios(copia)
{
}

PREMIUM::~PREMIUM(){
	delete ListaDescargas;//??
}


void PREMIUM::DescargarAyV(Servicios* servicio){
	*ListaDescargas + servicio;
}


ostream& PREMIUM::operator<<(ostream& out)
{
	Usuarios& P=*this;
	out << &P;//H
	out << *ListaDescargas;
	return out;
}


void PREMIUM::SeleccionarServicio(cListaT<Servicios>* serv)
{
	int pos = rand() % (serv->getCA());
	//int pos = 1;

	if ((*serv)[pos] != NULL)
	{
		Juegos* aux = dynamic_cast<Juegos*>((*serv)[pos]);
		if (aux!=NULL)
		{
			servicio = new Juegos(*aux);
		}
		AudioVisual* aux1 = dynamic_cast<AudioVisual*>((*serv)[pos]);
		if (aux1!=NULL)
		{
			servicio = new AudioVisual(*aux1);
		}
		Audio* aux2 = dynamic_cast<Audio*>((*serv)[pos]);
		if (aux2!=NULL)
		{
			servicio = new Audio(*aux2);
		}
		
		try
		{
			servicio->VerificarPais(this);
		}
		catch (exception& e)
		{
			throw e.what();
		}
		int rangoEtareo = servicio->ChequearEdad();
		if (Edad < 13 && rangoEtareo != 0)
		{
			throw exception("No tiene la edad suficiente para utilizar este servicio");
		}
		if (Edad < 18 && rangoEtareo == 2)
		{
			throw exception("No tiene la edad suficiente para utilizar este servicio");
		}
	}
	//si la edad>18 no tiene ninguna restriccion
}



void PREMIUM::Registrarse(Plataforma* plataforma){
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
