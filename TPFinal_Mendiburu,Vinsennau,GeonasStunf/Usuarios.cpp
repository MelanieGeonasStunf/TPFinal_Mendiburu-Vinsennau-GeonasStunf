///////////////////////////////////////////////////////////
//  Usuarios.cpp
//  Implementation of the Class Usuarios
//  Created on:      01-Jun-2021 10:49:54 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "Usuarios.h"
#include "Plataforma.h"
#include "PREMIUM.h"
#include "TipoUsuario.h"
#include "FREE.h"
#include "BASIC.h"

Usuarios::Usuarios(int Edad, Paises Pais, string Password, const string Name):UserName(Name)
{
	Estado = false;//usuario empieza desconectado
	this->Pais = Pais;
	this->Password = Password;
	servicio = NULL;//no pasamos servicio?- lo seteamos despues?
	cantConexSemana = 0;
	Eliminado = false;
}

Usuarios::~Usuarios(){

}

Usuarios::Usuarios(Usuarios& user) :Edad(user.Edad), Estado(user.Estado),
Pais(user.Pais), Password(user.Password), servicio(user.servicio), cantConexSemana(user.cantConexSemana),
Eliminado(user.Eliminado)//,Name(user.Name)??
{
}

void Usuarios::CerrarSesion(){
	if (!Estado)
		throw new exception("\nNunca debería pasar esto.");//vemos que hacemos
	Estado = false;
	setFHcierre();//vemos que hacemos
	RegUsuarios* regu = RegistrarenRegistro();
}


void Usuarios::IniciarSesion(Plataforma* plataforma){
	int pos = -1;
	if (plataforma != NULL)
	{
		try
		{
			pos = plataforma->m_Usuarios->BuscarItem1(UserName);
		}
		catch (exception& e)
		{
			throw e.what();
		}
		
		if (plataforma->m_Usuarios->vector[pos]->Password == Password)
		{
			Estado = true;//se inicia sesion
			setFHinicio();//le hacemos el local time?? 
			cListaT<RegUsuarios>* RegU = plataforma->getRgUsuarios();
			*RegU + RegistrarenRegistro();
			cantConexSemana++;
		}
			
	}
}
//idea! Hcemos un local time de inicio de registro del susuario y despues par setear el final 
//le agregamos un rand entre 0,24 y 10 horas que sea equivalente al tiempo de conección del usuario. De esta forma 
//no nos va a quedar el mismo tiempo de inicio que final oalgo así, igual hay que hacer que llegue a pasar una semana
//sin que necesariamente pase


RegUsuarios* Usuarios::RegistrarenRegistro(){
	//hacemos un registro y en el constructor le pasamos por parametros a reg usuarios los datos del usuario
	RegUsuarios* reg;
		
	
	if (dynamic_cast<PREMIUM*>(this)!= NULL )
	{
		reg = new RegUsuarios(UserName, premium);
	}
	if (dynamic_cast<BASIC*>(this) != NULL)
	{
		reg = new RegUsuarios(UserName, basic);
	}
	if (dynamic_cast<FREE*>(this) != NULL)
	{
		reg = new RegUsuarios(UserName, Free);
	}
	return reg;
}


void Usuarios::Registrarse(Usuarios* user, Plataforma* plataforma){//me parece que este metodo debería ser de plataforma, 
		//o no es necesario pasar el user pq podemos usar el puntero this!
	if (user == NULL)
		throw new exception("\nNo se pudo registrar el usuario ingresado.");
	if((plataforma->m_Usuarios->BuscarItem1(UserName))!=-1)
		throw new exception("\nEl nombre de usuario ingresado ya posee una cuenta" );//en este caso el usuario ya esta registrado
	*(plataforma->m_Usuarios) + user;
	Estado = true;//se inicia sesion
	setFHinicio();//capaz podemos directamente iniciar sesion y nos salteamos esta parte
	cListaT<RegUsuarios>* RegU = plataforma->getRgUsuarios();
	*RegU + RegistrarenRegistro();
	cantConexSemana++;
	
}


void Usuarios::setFHcierre(tm cierre)
{
	//le podemos ir pasando un parametro de tiempo que se le suma
	//por ej (entre iniciar sesion y seleccionar servicio le sumamos aprox 10 segundos)
	//despues le sumamos el tiempo que uso el servicio 
	//despues le sumamos otro tiempo que implique el cierre de la aplicacion, osea cuando cierra sesion 
	//no se si estaria mal suponer que el usuario se va a desconectar inmediatamente después de usar todo
}

void Usuarios::setFHinicio(tm inicio)
{
	/*time_t rawtime;
	tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	FechayHoraInicio = *info;
	*/
}

void Usuarios::setEliminado(bool elim)
{
	Eliminado = elim;
}

Paises Usuarios::getPais()
{
	return Pais;
}

bool Usuarios::VerificarContrasena()
{
	/*
	* REQUISITOS:
	* - +8 caracteres
	* - Mayuscula
	* - Numero
	* - Simbolo-> sin ; , : . " ' 
	* - Sin espacios
	*/

	if (Password.length() > 8 && Password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos
		&& Password.find_first_of("123456789") != string::npos && Password.find_first_of("~!@#$%^&*()<>?/\[]{}*+-_=") != string::npos &&
		Password.find_first_of(" ") == string::npos)
	{
		return true;
	}
		
	return false;
}
//PROBAR!

void Usuarios::SeleccionarServicio(cListaT <Servicios>* serv)
{
	int pos = rand() % (serv->getCA());
	//int pos = 1;

	if ((serv[pos]) != NULL)
	{
		servicio = new Servicios(serv[pos]);
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
		//servicio->Iniciar(this);
	}
	//si la edad>18 no tiene ninguna restriccion
}
//capaz podemos hacer un metodo de usuario que verifique cual es el tipo de usuario, como que haga toda la parte del dynamic cast
//y retorne el enum del tipo de usuario, la podriamos usar en varios metodos y ahorrarnos lineas de codigo