///////////////////////////////////////////////////////////
//  PREMIUM.h
//  Implementation of the Class PREMIUM
//  Created on:      01-Jun-2021 10:50:00 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_B5435F7E_5DB6_47db_B8D6_B63D1D13B9AB__INCLUDED_)
#define EA_B5435F7E_5DB6_47db_B8D6_B63D1D13B9AB__INCLUDED_

#include "Usuarios.h"
#include "Servicios.h"
#include "Librerias.h"

class PREMIUM : public Usuarios
{

public:
	PREMIUM();
	virtual ~PREMIUM();
	Servicios *m_Servicios;

	void AumentarCalidad();
	void DescargarAyV(Servicios* servicio);
	void Registrarse();
	void SeleccionarServicio(Servicios* servicio);

private:
	int CostoPremium;

};
#endif // !defined(EA_B5435F7E_5DB6_47db_B8D6_B63D1D13B9AB__INCLUDED_)
