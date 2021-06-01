///////////////////////////////////////////////////////////
//  RegistroJuegos.h
//  Implementation of the Class RegistroJuegos
//  Created on:      01-Jun-2021 10:50:19 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_DA998F8C_89E0_4421_9147_5BF0E3677882__INCLUDED_)
#define EA_DA998F8C_89E0_4421_9147_5BF0E3677882__INCLUDED_

#include "Juegos.h"
#include "Librerias.h"

class RegistroJuegos
{

public:
	RegistroJuegos();
	virtual ~RegistroJuegos();
	Juegos *m_Juegos;

private:
	int CantidadPartidasGanadas;
	tm Fecha;
	tm FechaUltimaJugada;
	int Nivel;
	const string UserName;

};
#endif // !defined(EA_DA998F8C_89E0_4421_9147_5BF0E3677882__INCLUDED_)
