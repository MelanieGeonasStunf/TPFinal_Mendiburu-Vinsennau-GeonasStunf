#include "Usuarios.h"
#include "Plataforma.h"
#include "PREMIUM.h"
#include "TipoUsuario.h"
#include "FREE.h"
#include "BASIC.h"
#include "Audio.h"
#include "AudioVisual.h"
#include "Juegos.h"
#include "funciones.h"

Usuarios::Usuarios(int Edad, Paises Pais, string Password, const string Name, string* tarjeta):UserName(Name)
{
	Estado = false;//usuario empieza desconectado
	this->Pais = Pais;
	this->Password = Password;
	this->tarjeta = NULL;
	servicio = NULL;//no pasamos servicio?- lo seteamos despues?
	cantConexSemana = 0;
	Eliminado = false;
	this->Edad = Edad;
	FechayHoraCierre = { 0,0,0 };
	FechayHoraInicio = { 0,0,0 };
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
	setFHcierre();
	FREE* usuarioF = dynamic_cast<FREE*>(this);
	if (usuarioF != NULL)
	{
		usuarioF->settiempoConex();
	}
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
		catch (exception* e)
		{
			throw *e;
		}
		
		if (plataforma->m_Usuarios->vector[pos]->Password == Password)
		{
			Estado = true;//se inicia sesion
			setFHinicio();//le hacemos el local time??
			FREE* usuarioF = dynamic_cast<FREE*>(this);
			if(usuarioF!=NULL)
			{
				if (usuarioF->getcontadorsem() == 0)
					usuarioF->setcontadorsem();
			}
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
	RegUsuarios* reg=NULL;
		
	
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





void Usuarios::setFHcierre()
{
	time_t rawtime;
	tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	FechayHoraCierre= *info;
	//le podemos ir pasando un parametro de tiempo que se le suma
	//por ej (entre iniciar sesion y seleccionar servicio le sumamos aprox 10 segundos)
	//despues le sumamos el tiempo que uso el servicio 
	//despues le sumamos otro tiempo que implique el cierre de la aplicacion, osea cuando cierra sesion 
	//no se si estaria mal suponer que el usuario se va a desconectar inmediatamente después de usar todo
}

void Usuarios::setFHinicio()
{
	FechayHoraInicio = setLocalTime();
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


istream& Usuarios::operator>>(istream& in) {
	cout << "\nIngrese el numero de la tarjeta: " << endl;
	int numero;
	in >> numero;
	return in;
}
ostream& Usuarios::operator<<(ostream& out)
{
	out<<"\nUser Name:"<<Clave<<"\nContrasenia:"<<Encriptar(Password)<<"\nServicio:"
	<<(*servicio)<<"\nEdad:"<<Edad<<"\nPais:"<<Pais<<"\nTarjeta:"<<Encriptar(tarjeta)<<endl;
	return out;
}

