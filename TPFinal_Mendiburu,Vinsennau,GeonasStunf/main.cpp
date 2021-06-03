#include "Librerias.h"
#include "Paises.h"
#include "eAudio.h"
#include "funciones.h"
#include "Archivos.h"
#include "Plataforma.h"
#include "PREMIUM.h"
#include "BASIC.h"
#include "FREE.h"

int main()
{
	Plataforma* Labflix = new Plataforma();
	// creamos archivo
	//Leemos archivo
	FREE* usuarioFree = new FREE(19, Francia, "EstaLoco00!", "Damian");
	PREMIUM* usuarioPremium = new PREMIUM(70, Argentina, "Bypass123-", "Rene", "06062002");
	//BASIC* usuarioBasic = new BASIC(14, Brasil, "Yanotengoimagination", "Coco", "11001100");
	BASIC* usuarioBasic = new BASIC(14, Brasil, "Yanotengoimagination<3", "Coco", "11001100");
	bool semana = false;

	do
	{
		
		Menu();
		//Guardamos archivo
		try
		{
			Casos(usuarioFree, 3);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			usuarioFree->CerrarSesion();
			break;
		}
		
		try
		{
			Casos(usuarioBasic, 2);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			usuarioBasic->CerrarSesion();
			break;
		}

		try
		{
			Casos(usuarioPremium, 1);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			usuarioPremium->CerrarSesion();
			break;
		}
		

		semana = tick();

	} while (semana==false);

	if (semana == true)
		Labflix->VerResumen();

	system("pause");

	delete Labflix;
}