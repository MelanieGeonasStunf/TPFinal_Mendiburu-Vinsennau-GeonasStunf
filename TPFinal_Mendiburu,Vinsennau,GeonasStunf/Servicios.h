///////////////////////////////////////////////////////////
//  Servicios.h
//  Implementation of the Class Servicios
//  Created on:      01-Jun-2021 10:49:56 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_3001E55B_D89E_4d2a_8642_8FB9B9A0975C__INCLUDED_)
#define EA_3001E55B_D89E_4d2a_8642_8FB9B9A0975C__INCLUDED_

#include "Usuarios.h"
#include "Librerias.h"

class Servicios
{

public:
	Servicios();
	virtual ~Servicios();
	Usuarios *m_Usuarios;

	void Apagar();
	void ChequearEdad();
	void Iniciar();
	void Pausar();
	void Reanudar();
	void VerificarPais();

private:
	const string Clave;
	tm duracion;
	const string Nombre;
	Paises* paises;
	int RegistrarenRegistro;

};
#endif // !defined(EA_3001E55B_D89E_4d2a_8642_8FB9B9A0975C__INCLUDED_)
