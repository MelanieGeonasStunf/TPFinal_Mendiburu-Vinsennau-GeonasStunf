#pragma once

//#include "Librerias.h"
#include "Paises.h"
#include "Servicios.h"
#include "RegUsuarios.h"
#include "TipoUsuario.h"
#include "cListaT.h"
//#include "AudioVisual.h"

class Plataforma;
class PREMIUM;
class BASIC;
class FREE;
class AudioVisual;
//class Audiovisual;
class Audio;

class Usuarios
{

protected:
	int Edad;
	bool Estado;
	tm FechayHoraCierre;
	tm FechayHoraInicio;
	Paises Pais;
	string Password;
	const string UserName;
	Servicios* servicio;//servicio que esta usando el usuario en el momento.
	int cantConexSemana;
	friend void ReproducirServicio(Usuarios* user, Plataforma* plataforma);
	bool Eliminado;////si es true-> iniciar sesion ->no puede iniciar
	bool calidad;
	//termina la semana-> en el main nos fijamos que usuarios estan en true y los eliminamos (delete)
	//si es false-> no pasa nada
	string* tarjeta;
	//int tiempoconex;->cuenta el tiempo de conexion del usuario que nos va a servir para setear el horario
	//del cierre de sesion y para limitar a los usuarios FREE.
	cListaT<AudioVisual>* ListadeRecientesAyV;
	cListaT <Audio>* ListaRecientesA;//tenia doble puntero y le saque uno

	
public:
	Usuarios(int Edad, Paises Pais,string Password, const string Name, string* tarjeta=NULL);
	virtual ~Usuarios();
	Usuarios(Usuarios& user);

	void CerrarSesion();
	void IniciarSesion(Plataforma* plataforma);//llamamos a casos y a menu2 ->virtual?
	//tiene que verificar que la contrasena y el user sean correctos->verificar en m_Usuarios de plataforma

	RegUsuarios* RegistrarenRegistro();//plataforma usa el registro
	virtual void Registrarse(Plataforma* plataforma) = 0;//->registra usuario!=iniciar sesion
	//tendria que ser virtual pura?-> esta en todos los hijos

	virtual void SeleccionarServicio(cListaT <Servicios> *serv)=0;
	/*se fija si el servicio que esta en la lista que le paso por parametro
	*/
	//hay alguna restriccion con free/premium?
	
	//getters y setters
	void setFHcierre();
	void setFHinicio();//PROBLEMA!!
	void setEliminado(bool elim);
	string getclave() { return UserName; };
	tm getFechayHoraCierre() { return FechayHoraCierre; };
	int getEdad() { return Edad; }
	Paises getPais();
	int getConex() { return cantConexSemana; }
	Servicios* getServ() { return servicio; }
	string getPass() { return Password; }
	bool getestadoEliminado() { return Eliminado; }
	//AGREGADO:
	bool VerificarContrasena();//verifica que cumpla requisitos-> ya hecha!
	
	void setTarjeta() { cin >> *tarjeta; }
	ostream& operator<<(ostream& out);
	istream& operator>>(istream& in);
};
