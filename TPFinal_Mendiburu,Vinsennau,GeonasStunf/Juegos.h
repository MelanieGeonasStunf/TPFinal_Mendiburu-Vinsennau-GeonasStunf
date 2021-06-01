///////////////////////////////////////////////////////////
//  Juegos.h
//  Implementation of the Class Juegos
//  Created on:      01-Jun-2021 10:50:01 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_8C869DA1_08CF_4a22_B90A_72531DA9985E__INCLUDED_)
#define EA_8C869DA1_08CF_4a22_B90A_72531DA9985E__INCLUDED_

#include "Servicios.h"
#include "Librerias.h"

class Juegos : public Servicios
{

public:
	Juegos();
	virtual ~Juegos();

	void GuardarProgreso();

private:
	int NivelFinal;
	string NombreJuego;

};
#endif // !defined(EA_8C869DA1_08CF_4a22_B90A_72531DA9985E__INCLUDED_)
