#include "funciones.h"
#include "Juegos.h"
#include "Audio.h"
#include "AudioVisual.h"

bool tick()
{
	return 0;
}

string Encriptar(string clave)
{
	int largo = clave.length();
	string encript;
	for(int i=0; i<largo;i++)
	{
		encript[i]='*';
	}
	return encript;
}

int Menu1()
{
	int opcion;
	cout << "------------MENU---------------" << endl;
	cout << " 1) Iniciar sesion" << endl <<
		"2) Registrarse" << endl <<
		"3) Salir" << endl;//sale del loop -> liberamos memoria usuario
	//cin >> opcion;
	opcion = 1 + rand() % 4;
	/*
	opcion=1;
	opcion=2;
	opcion=3;
	*/
	return opcion;
}

int Menu2()
{
	int opcion;
	cout << "------------MENU---------------" << endl;
	cout << " 1) Elegir Servicio" << endl <<
		"2) Editar cuenta" << endl <<//puede cambiarse de free a premium por ej o eliminarla?
		"3) Cerrar Sesion" << endl;
	//cin >> opcion;
	opcion = 1 + rand() % 4 ;
	/*
	opcion=1;
	opcion=2;
	opcion=3;
	*/
	return opcion;
}

void Casos1(Usuarios* user, Plataforma* plataforma)//lo hice en do while para que sea en loop
{
	int opcion;
	int opcion2;
	do {
		opcion = Menu1();
		switch (opcion)
		{
		case 1:
			try
			{
				user->IniciarSesion(plataforma);
				Casos2(user, plataforma);
			}
			catch (string exc)//si agarra excepcion significa que no se inicio sesion bien
			{//catch (e.what)!!
				cout << exc << endl;
				cout << "1) Desea registrarse?" << endl <<
					"2) Desea salir?" << endl;
				opcion2 = 1 + rand() % 3;
				if (opcion == 1)
					try {
					user->Registrarse(user, plataforma);//suponemos que al registrarse se inicia sesion 
					Casos2(user, plataforma);
				}
				catch (exception* e)
				{

					cout << e->what();
				}//deberiamos ver que el username no se repita??? sii
				else
					throw 3;//para que lo agarre en el main
			}
			break;

		case 2: {
			try {
				user->Registrarse(user, plataforma);
				Casos2(user, plataforma);
			}
			catch (exception* e)
			{

				cout << e->what();
			}
			break;
		}
		case 3:throw 3;
		}
	} while (opcion != 3);

}

void Casos2(Usuarios* user, Plataforma* plataforma)
{
	int opcion;
	//se hace infinitamenete
	do {
		opcion = Menu2();
		switch (opcion)
		{
		case 1:user->SeleccionarServicio(plataforma->m_Servicios);
			break;
		case 2:plataforma->EditarCuenta();
			break;
		case 3:
			try {
				user->CerrarSesion();
			}
			catch (...)
			{
				cout << "\nNo se pudo cerrar sesión" << endl;
			}
			break;
		}
	} while (opcion != 2);
}

long int PasarAseg(tm tiempo)
{
	long int tSeg = tiempo.tm_sec + tiempo.tm_min * 60 + tiempo.tm_hour * 3600;
	return tSeg;
}
void ReproducirServicio(Usuarios* user, Plataforma* plataforma)
{
	//ponemos el anuncio
	//dynamic cast

	Juegos* juego1 = dynamic_cast<Juegos*>(user->servicio);
	if (juego1 != NULL)
	{
		juego1->IniciarServicio();
		RegistroJuegos* regJ;
		regJ = juego1->RegistrarenRegistro(user->UserName);
		do {
			juego1->GuardarProgreso(regJ);
		} while (!juego1->getEstado());
	}
	AudioVisual* audiov1 = dynamic_cast<AudioVisual*>(user->servicio);
	if (audiov1!= NULL)
	{
		audiov1->IniciarServicio();
		long int TiempoReal = PasarAseg(audiov1->getDuracion());
		time_t i;
		time_t f;
		do
		{
		// string exc = "Fechas ingresadas no disponibles";
			
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				// Shift down
			}
			tm inicio;
			inicio.tm_year= (audiov1->getTInicio()).tm_year - 1900;
			tm* I = &inicio;
			time_t rawtime;
			time(&rawtime);
			tm*F = localtime(&rawtime);
			i= mktime(I);
			f = mktime(F);

		} while (difftime(f,i)<=TiempoReal);

	}
	if (dynamic_cast<Audio*>(user->servicio) != NULL)
	{
			//audiov1->IniciarServicio();
		long int TiempoReal = PasarAseg(audiov1->getDuracion());
		time_t i;
		time_t f;
		do
		{
		// string exc = "Fechas ingresadas no disponibles";
			
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				// Shift down
			}
			tm inicio;
			inicio.tm_year= (audiov1->getTInicio()).tm_year - 1900;
			tm* I = &inicio;
			time_t rawtime;
			time(&rawtime);
			tm*F = localtime(&rawtime);
			i= mktime(I);
			f = mktime(F);

		} while (difftime(f,i)<=TiempoReal);
	}


}