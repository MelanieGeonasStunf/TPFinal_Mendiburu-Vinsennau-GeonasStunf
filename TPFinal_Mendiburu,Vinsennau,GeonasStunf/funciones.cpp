#include "funciones.h"

bool tick()
{
	return 0;
}

void Encriptar(string clave)
{

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
			}
			catch (string exc)//si agarra excepcion significa que no se inicio sesion bien
			{//catch (e.what)!!
				cout << exc << endl;
				cout << "1) Desea registrarse?" << endl <<
					"2) Desea salir?" << endl;
				opcion2 = 1 + rand() % 3;
				if (opcion == 1)
					user->Registrarse(user, plataforma); //deberiamos ver que el username no se repita???
				else
					throw 3;//para que lo agarre en el main
			}
			break;

		case 2:user->Registrarse(user, plataforma);
			break;
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
