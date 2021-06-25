#include "Librerias.h"
#include "Paises.h"
#include "funciones.h"
#include "Archivos.h"
#include "Plataforma.h"
#include "PREMIUM.h"
#include "BASIC.h"
#include "FREE.h"
//#include "Juegos.h"


int main()
{
	//ANTES DE DESESPERAR-> fijarse si constructores / destructores estan bien :| 


	tm FechaInicio = setLocalTime();

	srand(time(NULL));
	Plataforma* Labflix = new Plataforma();
	// creamos archivo
	//Leemos archivo
	Labflix->m_Servicios = new cListaT<Servicios>();
	Servicios(Labflix->m_Servicios );
	Paises paisJ[4] = { Francia, Colombia, Argentina, España };
	Servicios* juego1 = new Juegos("789", "Pacwomen", 4, paisJ, nino ,2021);
	*Labflix->m_Servicios + juego1;

	Paises paisA[5] = { Chile, Colombia, Argentina, España, Venezuela };
	Servicios* audio1 = new Audio("382", "New Rules", 5, paisA, adolescente, { 44, 03, 00 });
	*Labflix->m_Servicios + audio1;

	Paises paisAV[7] = { Chile, EstadosUnidos, Bolivia, Paraguay, Venezuela , Canada, Peru};
	Servicios* audioyvideo1 = new AudioVisual("911", "Sobreviviendo Favaloro", 7, paisAV, adulto,{ 12, 5, 02 },1);//hay que hacer un enum de servicios
	*Labflix->m_Servicios + audioyvideo1;


	FREE* usuarioFree = new FREE(19, Francia, "EstaLoco00!", "Damian");

	PREMIUM* usuarioPremium = new PREMIUM(70, Argentina, "Bypass123-", "Rene", "06062002");
	PREMIUM* usuarioPremium1 = new PREMIUM(11,Venezuela , "Crisis", "LaBelu", "09082001");//mal la contrasena

	BASIC* usuarioBasic1 = new BASIC(13, Colombia, "Contra123-", "Ruperto", "42190416");
	BASIC* usuarioBasic = new BASIC(14, Brasil, "Yanotengoimagination<3", "Coco", "11001100");//tarjeta mal

	bool semana = false;

	do
	{
		//Guardamos archivo
		try
		{
			Casos1(usuarioFree, Labflix);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			break;
		}
		
		try
		{
			Casos1(usuarioBasic, Labflix);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			break;
		}

		try
		{
			Casos1(usuarioPremium, Labflix);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			break;
		}
		try
		{
			Casos1(usuarioPremium1, Labflix);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			
			break;
		}
		try
		{
			Casos1(usuarioBasic1, Labflix);
		}
		catch (int opcion)
		{
			cout << "Saliendo de Labflix..." << endl;
			break;
		}
		semana = tick();

	} while (semana==false);
	cout << *(Labflix->getUsuarios());
	//cout << *(plataforma->get);

	tm FechaFin = setLocalTime();
	if (semana == true)
		Labflix->VerResumen(FechaInicio, FechaFin);

	Labflix->PonerEnCeroConex();

	int cant = Labflix->getUsuarios()->getCA();
	for (int i = 0; i < cant; i++)
	{
		Usuarios* user = Labflix->getUsuarios()->vector[i];
		if (user->getestadoEliminado() == true) //eliminamos a los usuarios que anteriormente habian eliminado su cuenta durante la semana
			delete user;
	}
	//poner contador en 0
	system("pause");

	delete Labflix;
}