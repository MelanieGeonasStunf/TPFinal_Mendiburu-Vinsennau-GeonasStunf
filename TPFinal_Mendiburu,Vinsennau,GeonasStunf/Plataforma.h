#pragma once

#include "Servicios.h"
#include "Usuarios.h"
#include "Librerias.h"
#include "Juegos.h"
#include "Audio.h"
#include "AudioVisual.h"
#include "cListaT.h"
#include "RegUsuarios.h"
#include "RegistroAyV.h"
#include "RegistroJuegos.h"

class FREE;
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

	void EstadisticasPorContenido();
	cListaT <Audio> *MasEscuchados(tm Periodo);
	cListaT <Juegos> *MasJugados(tm FechaI, tm FechaF);
	cListaT <AudioVisual> *MasVistos(tm Periodo);
	//Periodo->pasar dos fechas o que te devuelva unicamente lo de la ultima semana.

	void PromedioConectadosenSemanaxDia();
	
	void VerResumen ();//da resumen de la semana

	//Usuarios* get
	void EditarCuenta(Usuarios*user, int tipo, bool eliminar);//no me toma el enum!
	//THROW!!!!
	
	//seters y geters
	cListaT<RegUsuarios>* getRgUsuarios() { return RegU; };
	cListaT<RegistroAyV>* getRgAyV() { return RegAyV; }
};

