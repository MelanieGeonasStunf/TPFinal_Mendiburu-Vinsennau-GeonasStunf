#include "funciones.h"
#include "Juegos.h"
#include "Audio.h"
#include "AudioVisual.h"
#include "FREE.h"
#include "Usuarios.h"
#include "Plataforma.h"
#include "Servicios.h"

tm setLocalTime()
{
	time_t rawtime;
	time(&rawtime);
	tm* hoy = localtime(&rawtime);
	return *hoy;
}

bool tick()
{
	tm hoy = setLocalTime();
	if (hoy.tm_hour == 0 && hoy.tm_min == 0 && hoy.tm_wday == 1)//si es lunes 
		return true;
	return false;
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
					user->Registrarse(plataforma);//suponemos que al registrarse se inicia sesion 
					Casos2(user, plataforma);
				}
				catch (exception* e)
				{
					cout << e->what();
					break;
				}
				else
					throw 3;//para que lo agarre en el main
			}
			break;

		case 2: {
			try {
				user->Registrarse(plataforma);
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
	FREE* f = dynamic_cast<FREE*>(user);
	//se hace infinitamenete
	do {
		opcion = Menu2();
		switch (opcion)
		{
		case 1:
		{
			try{
			user->SeleccionarServicio(plataforma->m_Servicios);
			}
			catch(exception*e)
			{
			throw e;
			}
			ReproducirServicio(user, plataforma);
			if(f!=NULL)
			{
				try{
					f->tiempoExcedido();
				}
				catch(exception*e)
				{
					throw e;
				}
			}
			break;
			}
		case 2:plataforma->EditarCuenta(user, rand()%3, rand()%1);//elige el tipo y si se elimina al azar
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
	/*
	* PAUSAR: " "(espacio)
	* REANUDAR: " "(espacio)
	* APAGAR: escape (Esc)
	* 
	*/
	bool pausado = false;
	long int tiempoModificado=0;
	cout << "-------------------" << endl <<
		"-Pausa: SPACE BAR" << endl <<
		"-Reanudar: SPACE BAR" << endl <<
		"-Apagar: ESC" << endl <<
		"----------------------" << endl;
	RegistroAyV* regA=NULL;
	FREE* usuarioF = dynamic_cast<FREE*>(user);
	if (usuarioF!=NULL)
	{
		usuarioF->Anuncios();//no se porque no lo toma :( -> tendria que ser virtual?
	}

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
	/*
	* PAUSAR: ESPACIO
	* REANUDAR: ESPACIO
	* RECORD: R
	* FAST F: flecha arriba
	* FAST B: flecha abajo
	*/
	RegistroAyV* regAV = NULL;
	if (audiov1!= NULL)
	{
		cout<<"-Fast forward: flecha arriba" << endl <<
			"-Fast Backward: flecha abajo" << endl <<
			"-Record: R" << endl <<
			"----------------------" << endl;
		audiov1->IniciarServicio();
		//determina si vio 30% y lo cuenta como visto/ no visto
		long int TiempoReal = PasarAseg(audiov1->getDuracion());
		
		time_t i;
		time_t f;
		clock_t t;
		int seg = 0;
		do
		{
	
			
			if (GetKeyState(VK_SPACE) & 0x8000)//PAUSA-> tendriamos que poner el espacio
			{
				//podemos poner todo esto adentro de pausa sino, no se si es necesario el system pause
		
				user->servicio->Pausar();
				t = clock();//empieza a contar el tiempo
				//solo se puede reanudar si esta pausado!
				if (GetKeyState(VK_SPACE) & 0x8000)//REANUDA con espacio tambien
				{
					t = clock() - t;//termina de contar el tiempo
					user->servicio->Reanudar();
					seg = (t) / CLOCKS_PER_SEC;
					TiempoReal += seg;
					tiempoModificado += seg;
				}
			}
			if (GetKeyState(VK_UP) & 0x8000)//flecha arriba
			{
				audiov1->FastForward(tiempoModificado,TiempoReal);//siempre adelantamos 10 seg
			}
			if (GetKeyState(VK_DOWN) & 0x8000)//flecha abajo
			{
				audiov1->FastBackward(tiempoModificado,TiempoReal);
				//TiempoReal += 10;
			}
			/*
			mas opciones !!-> NO OLVIDAR
			*/
			if (GetKeyState(VK_ESCAPE) & 0x8000)//APAGAR-> Esc
			{
				user->servicio->Apagar();
				//tenemos que llamar a la funcion que controla si vio 30% 
				bool ok=audiov1->GuardartiempoRep(TiempoReal-tiempoModificado);
				regAV=audiov1->RegistrarenRegistro(user,ok);
				
				*(plataforma->getRgAyV()) + regAV;
				return;
			}
			if (GetKeyState(VK_UP) & 0x8000)//flecha arriba
			{
				audiov1->FastForward(tiempoModificado, TiempoReal);//siempre adelantamos 10 seg
				
			}
			if (GetKeyState(VK_DOWN) & 0x8000)//flecha abajo
			{
				audiov1->FastBackward(tiempoModificado, TiempoReal);
				
			}
			//
			if (GetKeyState('R') & 0x8000)//letra R
			{
				audiov1->Record();
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
		bool ok= audiov1->GuardartiempoRep(TiempoReal - tiempoModificado);
		regAV=audiov1->RegistrarenRegistro(user, ok);
		
		*(plataforma->getRgAyV()) + regAV;
	}
	Audio* audio = dynamic_cast<Audio*>(user->servicio);
	if (dynamic_cast<Audio*>(audio) != NULL)
	{
		cout << "-Fast forward: flecha arriba" << endl <<
			"-Fast Backward: flecha abajo" << endl <<
			"-Record: R" << endl <<
			"----------------------" << endl;
		audio->IniciarServicio();
		//RegistroAyV* regA;
		long int TiempoReal = PasarAseg(audio->getDuracion());
		time_t i;
		time_t f;
		clock_t t;
		int seg = 0;
		do
		{
		// string exc = "Fechas ingresadas no disponibles";
			if (GetKeyState(VK_SPACE) & 0x8000)//PAUSA-> tendriamos que poner el espacio
			{
				// Shift down
				user->servicio->Pausar();
				t = clock();//empieza a contar el tiempo
				//solo se puede reanudar si esta pausado!
				if (GetKeyState(VK_SPACE) & 0x8000)//REANUDA con espacio tambien
				{
					t = clock() - t;//termina de contar el tiempo
					user->servicio->Reanudar();
					int seg = (t) / CLOCKS_PER_SEC;//retorna seg que estuvo pausado
					TiempoReal += seg;
					tiempoModificado += seg;
				}
			}
			if (GetKeyState(VK_ESCAPE) & 0x8000)//APAGAR-> Esc
			{
				user->servicio->Apagar();
				//tenemos que llamar a la funcion que controla si vio 30% 
				regA = audio->RegistrarenRegistro(user,audio->GuardartiempoRep(TiempoReal-tiempoModificado));
				*(plataforma->getRgAyV()) + regA;
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
		regA = audio->RegistrarenRegistro(user,audio->GuardartiempoRep(TiempoReal-tiempoModificado));
		*(plataforma->getRgAyV()) + regA;
	}
}
void Servicios(cListaT<Servicios>*p){
	Paises paisA2[4] = { Chile, Colombia, Argentina,Francia};
	Paises paisJ2[3] = { Francia, Argentina, España };
	Paises paisAV2[2] = { EstadosUnidos,Canada };
	Servicios* juego2 = new Juegos("662", "subway surfers", 4, paisJ2, nino ,2014);
	Servicios* audio2 = new Audio("152", "Mamma Mia", 3, paisA2, adolescente, { 12, 05, 00 });
	Servicios* audioyvideo2 = new AudioVisual("982", "Fast&Fourious", 2, paisAV2, adulto,{ 03, 54, 04 });
	*p+juego2;
	*p+audio2;
	*p+audioyvideo2;
	//------------------------------------------------------------------------------------------------------
	Paises paisA3[2] = { Mexico,Paraguay};
	Paises paisJ3[1] = { Peru };
	Paises paisAV3[2] = { Australia};
	Servicios* juego3 = new Juegos("831", "minecraft", 2, paisJ3, adolescente ,2014);
	Servicios* audio3 = new Audio("670", "Kiwi", 1, paisA3, adulto, { 56, 02, 00 });
	Servicios* audioyvideo3 = new AudioVisual("42", "Buscando a Nemo", 1, paisAV3, nino,{ 03, 54, 04 });
	*p+juego3;
	*p+audio3;
	*p+audioyvideo3;
	//------------------------------------------------------------------------------------------------------
	Paises paisA4[2] = { Argentina,Francia};
	Paises paisJ4[1] = { Uruguay};
	Paises paisAV4[1] = {Chile};
	Servicios* juego4 = new Juegos("021", "Temple Run", 3, paisJ4, nino ,2011);
	Servicios* audio4 = new Audio("962", "Dangerous Woman", 2, paisA4, adolescente, { 35, 04, 01 });
	Servicios* audioyvideo4 = new AudioVisual("156", "Rey Leon", 1, paisAV, adolescente,{ 01, 00, 02 });
	*p+juego4;
	*p+audio4;
	*p+audioyvideo4;
}
