#include "Librerias.h"
#include "Paises.h"
#include "eAudio.h"
#include "funciones.h"
#include "Archivos.h"
#include "Plataforma.h"
#include "PREMIUM.h"
#include "BASIC.h"
#include "FREE.h"
//#include "Juegos.h"


/*
Podemos hacer un numero en basic y premium que aumente % cada 6 meses -> asi el precio 
del servicio aumenta.
*/
int main()
{
	//ANTES DE DESESPERAR-> fijarse si constructores / destructores estan bien :| 



	srand(time(NULL));
	Plataforma* Labflix = new Plataforma();
	// creamos archivo
	//Leemos archivo
	Labflix->m_Servicios = new cListaT<Servicios>;
	Paises paisJ[4] = { Francia, Colombia, Argentina, España };
	Juegos* juego1 = new Juegos("789", "Pacwomen", 4, paisJ, nino ,2021);
	*Labflix->m_Servicios + juego1;

	Paises paisA[5] = { Chile, Colombia, Argentina, España, Venezuela };
	Audio* audio1 = new Audio("382", "New Rules", 5, paisA, adolescente, { 44, 03, 00 });
	*Labflix->m_Servicios + audio1;

	Paises paisAV[7] = { Chile, EstadosUnidos, Bolivia, Paraguay, Venezuela , Canada, Peru};
	AudioVisual* audioyvideo1 = new AudioVisual("911", "Sobreviviendo Favaloro", 7, paisAV, adulto,{ 12, 5, 02 },/*NO SE QUE PONER DE TIPO*/);
	*Labflix->m_Servicios + audioyvideo1;

	FREE* usuarioFree = new FREE(19, Francia, "EstaLoco00!", "Damian");

	PREMIUM* usuarioPremium = new PREMIUM(70, Argentina, "Bypass123-", "Rene", "06062002");
	PREMIUM* usuarioPremium1 = new PREMIUM(11,Venezuela , "Crisis", "LaBelu", "09082001");//mal la contrasena

	BASIC* usuarioBasic1 = new BASIC(13, Colombia, "Contra123-", "Ruperto", "42190416");//tarjeta mal
	BASIC* usuarioBasic = new BASIC(14, Brasil, "Yanotengoimagination<3", "Coco", "11001100");

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

	if (semana == true)
		Labflix->VerResumen();
	//una vez pasada la semana no olvidar eliminar a todos los usuarios con Eliminado=true!!!

	system("pause");

	delete Labflix;
}