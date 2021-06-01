///////////////////////////////////////////////////////////
//  Plataforma.h
//  Implementation of the Class Plataforma
//  Created on:      01-Jun-2021 10:49:51 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_9B808780_E43A_492c_AE7D_6BA9FE780B0F__INCLUDED_)
#define EA_9B808780_E43A_492c_AE7D_6BA9FE780B0F__INCLUDED_

#include "Servicios.h"
#include "Usuarios.h"
#include "Librerias.h"

class Plataforma
{

public:
	Plataforma();
	virtual ~Plataforma();
	Servicios *m_Servicios;
	Usuarios *m_Usuarios;

	void EstadisticasPorContenido();
	Audio** MasEscuchados(tm Periodo);
	Juegos** MasJugados(tm Periodo);
	AudioVisual** MasVistos(tm Periodo);
	void PromedioConectadosDia();
	void PromedioConectadosSemana();
	void VerResumen(tm Periodo);

private:
	int CantidadUsuariosConectados;
	Usuarios** ListaUsuariosxDia;
	const string Nombre;
	int UsuariosxSemana;

};
#endif // !defined(EA_9B808780_E43A_492c_AE7D_6BA9FE780B0F__INCLUDED_)
