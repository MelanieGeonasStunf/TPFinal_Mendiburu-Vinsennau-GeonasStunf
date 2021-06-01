///////////////////////////////////////////////////////////
//  RegUsuarios.h
//  Implementation of the Class RegUsuarios
//  Created on:      01-Jun-2021 10:50:22 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_64EADC80_A977_4110_A8C7_0B3D3DDEA0D8__INCLUDED_)
#define EA_64EADC80_A977_4110_A8C7_0B3D3DDEA0D8__INCLUDED_

#include "Usuarios.h"
#include "Librerias.h"

class RegUsuarios
{

public:
	RegUsuarios();
	virtual ~RegUsuarios();
	Usuarios *m_Usuarios;

	void BuscarTipoUsuario();

private:
	tm Fecha;
	int TipoUsuario;
	int UserName;

};
#endif // !defined(EA_64EADC80_A977_4110_A8C7_0B3D3DDEA0D8__INCLUDED_)
