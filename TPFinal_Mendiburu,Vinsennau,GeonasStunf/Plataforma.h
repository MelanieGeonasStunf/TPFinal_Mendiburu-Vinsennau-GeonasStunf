#pragma once

#include "Servicios.h"
#include "Usuarios.h"
#include "Librerias.h"
#include "Juegos.h"
#include "Audio.h"
#include "AudioVisual.h"
//#include "cListaT.h"
#include "RegUsuarios.h"
#include "RegistroAyV.h"
#include "RegistroJuegos.h"
#include "FREE.h"
//class FREE;
class BASIC;
class PREMIUM;

class Plataforma
{
private:
	int CantidadUsuariosConectados;
	
	//cListaT <Usuarios>* ListaUsuariosxDia;
	const string Nombre;
	int UsuariosxSemana;
	
	cListaT<RegUsuarios>* RegU;
	cListaT<RegistroJuegos>* RegJ;
	cListaT<RegistroAyV>* RegAyV;

	//AGREGADO:
	Paises* paises;

public:
	cListaT <Servicios>* m_Servicios;
	cListaT <Usuarios>* m_Usuarios;

	Plataforma();
	virtual ~Plataforma();

	void EstadisticasPorContenido(Servicios*serv, tm FechaI, tm FechaF);
	string *MasEscuchados(tm FechaI, tm FechaF);
	string *MasJugados(tm FechaI, tm FechaF);
	string *MasVistos(tm FechaI, tm FechaF);
	//Periodo->pasar dos fechas o que te devuelva unicamente lo de la ultima semana.

	void PromedioConectadosenSemanaxDia();
	
	void VerResumen (tm FechaI, tm FechaF);//da resumen de la semana

	//Usuarios* get
	void EditarCuenta(Usuarios*user, int tipo, bool eliminar);//no me toma el enum!
	//THROW!!!!
	
	//seters y geters
	cListaT<RegUsuarios>* getRgUsuarios() { return RegU; };
	cListaT<RegistroAyV>* getRgAyV() { return RegAyV; }
};

