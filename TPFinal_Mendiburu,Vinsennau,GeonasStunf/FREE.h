///////////////////////////////////////////////////////////
//  FREE.h
//  Implementation of the Class FREE
//  Created on:      01-Jun-2021 10:49:57 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_66EF5C4A_48DA_415c_9A73_F1E0ED52452E__INCLUDED_)
#define EA_66EF5C4A_48DA_415c_9A73_F1E0ED52452E__INCLUDED_

#include "Usuarios.h"
#include "Librerias.h"

class FREE : public Usuarios
{

public:
	FREE();
	virtual ~FREE();

	void Anuncios();
	void LimiteTiempo();
	void Registrarse();
	void SeleccionarServicio();
	void VariarLista();

private:
	static int LimiteTiempoMax;

};
#endif // !defined(EA_66EF5C4A_48DA_415c_9A73_F1E0ED52452E__INCLUDED_)
