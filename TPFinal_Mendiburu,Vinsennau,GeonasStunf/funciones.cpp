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
	cin >> opcion;
	return opcion;
}

int Menu2()
{
	int opcion;
	cout << "------------MENU---------------" << endl;
	cout << " 1) Elegir Servicio" << endl <<
		"2) Editar cuenta" << endl <<//puede cambiarse de free a premium por ej
		"3) Cerrar Sesion" << endl;
	//cin >> opcion;
	opcion = 1 + rand() % 4 ;
	return opcion;
}

void Casos1(Usuarios* user, Plataforma* plataforma)
{
	int opcion = Menu1();
	int opcion2;
	switch (opcion)
	{
	case 1:
		try
		{
			user->IniciarSesion(plataforma);
		}
		catch (string exc)//si agarra excepcion significa que no se inicio sesion bien
		{
			cout << exc << endl;
			cout << "1) Desea registrarse?" << endl <<
				"2) Desea salir?" << endl;
			opcion2 = 1 + rand() % 3;
			if (opcion == 1)
				user->Registrarse();
			else
				throw 3;//para que lo agarre en el main
		}
		break;
		
	case 2:user->Registrarse();
		break;
	case 3:throw 3;
	}
}

void Casos2(Usuarios* user, Plataforma* plataforma)
{
	int opcion = Menu2();
	switch (opcion)
	{
	case 1:user->SeleccionarServicio(plataforma->m_Servicios);
		break;
	case 2:user->EditarCuenta();
		break;
	case 3:user->CerrarSesion();
		break;
	}
}
