///////////////////////////////////////////////////////////
//  BASIC.h
//  Implementation of the Class BASIC
//  Created on:      01-Jun-2021 10:49:59 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_19CA766C_DE95_4789_9F6E_055A1428EEA9__INCLUDED_)
#define EA_19CA766C_DE95_4789_9F6E_055A1428EEA9__INCLUDED_

#include "Usuarios.h"
#include "Librerias.h"

class BASIC : public Usuarios
{

public:
	BASIC();
	virtual ~BASIC();

	void Registrarse();
	void SeleccionarServicio();

private:
	int CostoBasic;

};
#endif // !defined(EA_19CA766C_DE95_4789_9F6E_055A1428EEA9__INCLUDED_)
