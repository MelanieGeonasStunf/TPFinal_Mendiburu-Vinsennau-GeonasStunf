#include "BASIC.h"
#define CostoB 200.00//defino costo basic
#include "Plataforma.h"
float BASIC::CostoBasic = CostoB;
BASIC::BASIC(int Edad, Paises Pais, string Password, const string Name, string* tarjeta):
Usuarios(Edad, Pais, Password, Name, false, tarjeta)
{
}

BASIC::~BASIC(){

}

BASIC::BASIC(Usuarios& user):Usuarios(user)
{
}


void BASIC::Registrarse(Plataforma* plataforma)
{
	if (this == NULL)
		throw new exception("\nNo se pudo registrar el usuario ingresado.");
	try {
		if ((plataforma->m_Usuarios->BuscarItem1(UserName)) != -1)
			throw new exception("\nEl nombre de usuario ingresado ya posee una cuenta");//en este caso el usuario ya esta registrado
	}
	catch (exception* e)
	{
		cout<<e->what()<<endl;
	}
	try {
		*(plataforma->m_Usuarios) + this;
	}
	catch (Usuarios* no)
	{
		throw no;
	}
	Estado = true;//se inicia sesion
	setFHinicio();
	cListaT<RegUsuarios>* RegU = plataforma->getRgUsuarios();
	RegUsuarios*u= RegistrarenRegistro();
	*RegU + u;
	cantConexSemana++;
}


void BASIC::SeleccionarServicio(cListaT<Servicios>* serv)
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

