#include "Plataforma.h"
#include "FREE.h"
#include "BASIC.h"
#include "PREMIUM.h"
#include "cListaT.h"
Plataforma::Plataforma():Nombre("Labflix")
{
	this->CantidadUsuariosConectados=0;
	//ListaUsuariosxDia = new cListaT<Usuarios>;
	this-> UsuariosxSemana=0;
	m_Servicios=new cListaT<Servicios>();
	m_Usuarios= new cListaT<Usuarios>();
	
	paises=new Paises[14]{Argentina, Chile,	Peru, Brasil, Colombia,	Mexico,	EstadosUnidos,
	Canada,Bolivia,	Paraguay,	Uruguay,	Venezuela,	España,	Francia};
}

Plataforma::~Plataforma(){
	//delete ListaUsuariosxDia;
	delete m_Usuarios;
	delete m_Servicios;
}

void Plataforma::setUsuariosxSemana()
{
for(int i=0;i<m_Usuarios->getCA();i++)
{
	UsuariosxSemana = m_Usuarios->vector[i]->getConex();//cantidad de usuarios conectados por semana.
}
}

void Plataforma::EstadisticasPorContenido(Servicios*serv, tm FechaI, tm FechaF){

	if (dynamic_cast<Juegos*>(serv))
	{
		string* MJ = MasJugados(FechaI, FechaF);
		cout << "Mas jugados: " << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "-" << MJ[i] << endl;
		}
	}
	if (dynamic_cast<Audio*>(serv))
	{
		string* ME = MasEscuchados(FechaI, FechaF);
		cout << "Mas escuchados: " << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "-" << ME[i] << endl;
		}
	}
	if (dynamic_cast<AudioVisual*>(serv))
	{
		string* MV = MasVistos(FechaI, FechaF);
		cout << "Mas vistos: " << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "-" << MV[i] << endl;
		}
	}
}

string* Plataforma::MasEscuchados(tm FechaI, tm FechaF){

	int cantAudio = RegAyV->getCA();
	//cListaT<Juegos>* masJug = new cListaT<Juegos>(5);//solo nos fijamos los 5 mas jugados
	string* masEsc = new string[3];
	int mE = -1;//no hay juego que se haya jugado menos de una vez
	int mE2 = -1;
	int mE1 = -1;

	int cont = 0;//cuenta cuantos juegos estan dentro del periodo pedido
	cListaT<RegistroAyV>* VistosEnPeriodo = NULL;

	for (int i = 0; i < cantAudio; i++)
	{
		//me fijo que el juego se haya jugado en el periodo de tiempo pedido
		if (RegAyV->vector[i]->getFecha().tm_year >= FechaI.tm_year && RegAyV->vector[i]->getFecha().tm_year <= FechaF.tm_year)
		{
			//estan dentro de los anios pedidos
			if (RegAyV->vector[i]->getFecha().tm_mon >= FechaI.tm_mon && RegAyV->vector[i]->getFecha().tm_mon <= FechaF.tm_mon)
			{
				//tienen distinto mes, tenemos que comparar el dia
				if (RegAyV->vector[i]->getFecha().tm_mday >= FechaI.tm_mday && RegAyV->vector[i]->getFecha().tm_mday <= FechaF.tm_mday)
				{
					//tienen distino dia, comparamos las horas

					if (RegAyV->vector[i]->getFecha().tm_hour >= FechaI.tm_hour && RegAyV->vector[i]->getFecha().tm_hour <= FechaF.tm_hour)
					{
						//tienen hora distinta, me fijo los minutos
						if (RegAyV->vector[i]->getFecha().tm_min >= FechaI.tm_min && RegAyV->vector[i]->getFecha().tm_min <= FechaF.tm_min)
						{
							//tienen minutos distinto me fijo los segundos
							if (RegAyV->vector[i]->getFecha().tm_sec >= FechaI.tm_sec && RegAyV->vector[i]->getFecha().tm_sec <= FechaF.tm_sec)
							{
								//si entra, significa que esta en el periodo de tiempo pedido

								VistosEnPeriodo[VistosEnPeriodo->getCA()] = RegAyV[i];//H

							}

						}
					}
				}

			}

		}

		//significa que no esta entre el periodo de anios pedido
		for (int i = 0; i < VistosEnPeriodo->getCA(); i++)
		{
			for (int j = 0; j < m_Servicios->getCA(); j++)
			{
				Audio* A = dynamic_cast<Audio*>(m_Servicios->vector[j]);
				if (A != NULL)
				{
					if (VistosEnPeriodo->vector[i]->getNombre() == A->getNombre())
					{
						A->setCant();
					}

				}


			}
		}

		for (int i = 0; i < m_Servicios->getCA(); i++)
		{
			Audio* A = dynamic_cast<Audio*>(m_Servicios->vector[i]);
			//buscamos los 5 maximos

			if (A != NULL)
			{
				if (A->getCant() > mE)
				{
					masEsc[0] = A->getNombre();
					mE = A->getCant();
				}

				if (A->getCant() >= mE1 && A->getNombre() != masEsc[0])
				{
					masEsc[1] = A->getNombre();
					mE1 = A->getCant();
				}
				if (A->getCant() >= mE2 && A->getNombre() != masEsc[0] && A->getNombre() != masEsc[1])
				{
					masEsc[2] = A->getNombre();
					mE2 = A->getCant();

				}
			}
		}

		return  masEsc;
	}
}


string* Plataforma::MasJugados(tm FechaI, tm FechaF) {

	int cantJuegos = RegJ->getCA();
	//cListaT<Juegos>* masJug = new cListaT<Juegos>(5);//solo nos fijamos los 5 mas jugados
	string* masJug = new string[3];
	int mJ=-1;
	int mJ2 = -1;
	int mJ1 = -1;

	int cont = 0;//cuenta cuantos juegos estan dentro del periodo pedido
	cListaT<RegistroJuegos>* JugadosEnPeriodo = NULL;

	for (int i = 0; i < cantJuegos; i++)
	{
		//me fijo que el juego se haya jugado en el periodo de tiempo pedido
		if (RegJ->vector[i]->getFechaUltJ().tm_year >= FechaI.tm_year && RegJ->vector[i]->getFechaUltJ().tm_year <= FechaF.tm_year)
		{
			//estan dentro de los anios pedidos
			if (RegJ->vector[i]->getFechaUltJ().tm_mon >= FechaI.tm_mon && RegJ->vector[i]->getFechaUltJ().tm_mon <= FechaF.tm_mon)
			{
				//tienen distinto mes, tenemos que comparar el dia
				if (RegJ->vector[i]->getFechaUltJ().tm_mday >= FechaI.tm_mday && RegJ->vector[i]->getFechaUltJ().tm_mday <= FechaF.tm_mday)
				{
					//tienen distino dia, comparamos las horas

					if (RegJ->vector[i]->getFechaUltJ().tm_hour >= FechaI.tm_hour && RegJ->vector[i]->getFechaUltJ().tm_hour <= FechaF.tm_hour)
					{
						//tienen hora distinta, me fijo los minutos
						if (RegJ->vector[i]->getFechaUltJ().tm_min >= FechaI.tm_min && RegJ->vector[i]->getFechaUltJ().tm_min <= FechaF.tm_min)
						{
							//tienen minutos distinto me fijo los segundos
							if (RegJ->vector[i]->getFechaUltJ().tm_sec >= FechaI.tm_sec && RegJ->vector[i]->getFechaUltJ().tm_sec <= FechaF.tm_sec)
							{
								//si entra, significa que esta en el periodo de tiempo pedido

								JugadosEnPeriodo[JugadosEnPeriodo->getCA()] = RegJ[i];//H

							}

						}
					}
				}

			}

		}

		//significa que no esta entre el periodo de anios pedido
		for (int i = 0; i < JugadosEnPeriodo->getCA(); i++)
		{
			for (int j = 0; j < m_Servicios->getCA(); j++)
			{
				Juegos* ju = dynamic_cast<Juegos*>(m_Servicios->vector[j]);
				if (ju != NULL)
				{
					if (JugadosEnPeriodo->vector[i]->getNombre() == ju->getNombre())
					{
						ju->setCont();
					}

				}


			}
		}
		mJ = -1;//no hay juego que se haya jugado menos de una vez
		for (int i = 0; i < m_Servicios->getCA(); i++)
		{
			Juegos* ju = dynamic_cast<Juegos*>((m_Servicios->vector[i]));
			//buscamos los 5 maximos

			if (ju != NULL)
			{
				if (ju->getCont() > mJ)
				{
					masJug[0] = ju->getNombre();
					mJ = ju->getCont();
				}

				if (ju->getCont() >= mJ1 && ju->getNombre() != masJug[0])
				{
					masJug[1] = ju->getNombre();
					mJ1 = ju->getCont();
				}
				if (ju->getCont() >= mJ2 && ju->getNombre() != masJug[0] && ju->getNombre() != masJug[1])
				{
					masJug[2] = ju->getNombre();
					mJ2 = ju->getCont();

				}
			}
		}
	}
		return  masJug;
}


string* Plataforma::MasVistos(tm FechaI, tm FechaF)
{

	int cantVideos = RegAyV->getCA();
	//cListaT<Juegos>* masJug = new cListaT<Juegos>(5);//solo nos fijamos los 5 mas jugados
	string* masVis = new string[3];
	int mV = -1;//no hay juego que se haya jugado menos de una vez
	int mV2 = -1;
	int mV1 = -1;

	int cont = 0;//cuenta cuantos juegos estan dentro del periodo pedido
	cListaT<RegistroAyV>* VistosEnPeriodo = NULL;

	for (int i = 0; i < cantVideos; i++)
	{
		//me fijo que el juego se haya jugado en el periodo de tiempo pedido
		if (RegAyV->vector[i]->getFecha().tm_year >= FechaI.tm_year && RegAyV->vector[i]->getFecha().tm_year <= FechaF.tm_year)
		{
			//estan dentro de los anios pedidos
			if (RegAyV->vector[i]->getFecha().tm_mon >= FechaI.tm_mon && RegAyV->vector[i]->getFecha().tm_mon <= FechaF.tm_mon)
			{
				//tienen distinto mes, tenemos que comparar el dia
				if (RegAyV->vector[i]->getFecha().tm_mday >= FechaI.tm_mday && RegAyV->vector[i]->getFecha().tm_mday <= FechaF.tm_mday)
				{
					//tienen distino dia, comparamos las horas

					if (RegAyV->vector[i]->getFecha().tm_hour >= FechaI.tm_hour && RegAyV->vector[i]->getFecha().tm_hour <= FechaF.tm_hour)
					{
						//tienen hora distinta, me fijo los minutos
						if (RegAyV->vector[i]->getFecha().tm_min >= FechaI.tm_min && RegAyV->vector[i]->getFecha().tm_min <= FechaF.tm_min)
						{
							//tienen minutos distinto me fijo los segundos
							if (RegAyV->vector[i]->getFecha().tm_sec >= FechaI.tm_sec && RegAyV->vector[i]->getFecha().tm_sec <= FechaF.tm_sec)
							{
								//si entra, significa que esta en el periodo de tiempo pedido

								VistosEnPeriodo[VistosEnPeriodo->getCA()] = RegAyV[i];//H

							}

						}
					}
				}

			}

		}

		//significa que no esta entre el periodo de anios pedido
		for (int i = 0; i < VistosEnPeriodo->getCA(); i++)
		{
			for (int j = 0; j < m_Servicios->getCA(); j++)
			{
				AudioVisual* AV = dynamic_cast<AudioVisual*>(m_Servicios->vector[j]);
				if (AV != NULL)
				{
					if (VistosEnPeriodo->vector[i]->getNombre() == AV->getNombre())
					{
						AV->setCant();
					}

				}


			}
		}

		for (int i = 0; i < m_Servicios->getCA(); i++)
		{
			AudioVisual* AV = dynamic_cast<AudioVisual*>(m_Servicios->vector[i]);
			//buscamos los 5 maximos

			if (AV != NULL)
			{
				if (AV->getCant() > mV)
				{
					masVis[0] = AV->getNombre();
					mV = AV->getCant();
				}

				if (AV->getCant() >= mV1 && AV->getNombre() != masVis[0])
				{
					masVis[1] = AV->getNombre();
					mV1 = AV->getCant();
				}
				if (AV->getCant() >= mV2 && AV->getNombre() != masVis[0] && AV->getNombre() != masVis[1])
				{
					masVis[2] = AV->getNombre();
					mV2 = AV->getCant();

				}
			}
		}

		return  masVis;
	}
}

int Plataforma::PromedioConectadosenSemanaxDia()
{
	int cant = UsuariosxSemana / 7;
	return cant;
}

void Plataforma::VerResumen(tm FechaI, tm FechaF){
	//imprimimos todo :)
	cout << "--------RESUMEN-----------" << endl;
	string* MV = MasVistos(FechaI,FechaF);
	string* ME = MasEscuchados(FechaI, FechaF);
	string* MJ = MasJugados(FechaI, FechaF);

	//imprimimos los 3 mas vistos, escuchados y jugados de la semana.
	//ponemos el periodo en el main
	cout << "Mas vistos: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "-" << MV[i] << endl;
	}
	cout << "Mas escuchados: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "-" << ME[i] << endl;
	}
	cout << "Mas jugados: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "-" << MJ[i] << endl;
	}

	cout << "Promedio de usuarios conectados en la semana: " << PromedioConectadosenSemanaxDia() << endl;

}

void Plataforma::EditarCuenta(Usuarios* user, int tipo, bool eliminar)
{	/*
	* 2 OPCIONES:
	* -Eliminar Cuenta.
	* -Cambiar tipo usuario.
	*/
	int t = -1;
	if (eliminar == true)
	{
		user->setEliminado(true);//=> se elimina al final de la semana para no tener problemas de memoria.
	}
	else//editamos la cuenta.
	{
		//dependiendo el tipo del usuario es 0,1,2 (corresponde con el enum)
		if (dynamic_cast<FREE*>(user) != NULL)
		{
			t = 0;
		}
		if (dynamic_cast<BASIC*>(user) != NULL)
		{
			t = 1;
		}
		if (dynamic_cast<PREMIUM*>(user) != NULL)
		{
			t = 2;
		}
		if (tipo == Free && t!=0)
		{
			//hacemos funcion que copia al usuario y lo pasa a free
			FREE* cambiado = new FREE(*user);
			user->setEliminado(true);
			if (tipo == 2)//significa que era premium 
			{
				cambiado->setCalidad();
				//de premium a free->baja calidad
			}
			*m_Usuarios + cambiado;
		}
		else if (tipo == basic && t!=1)
		{
			BASIC* cambiado = new BASIC(*user);
			if (t == 2)//significa que era premium y ya tengo datos de una tarjeta.
			{
				*m_Usuarios + cambiado;
				user->setEliminado(true);
				cambiado->setCalidad();
				//de premium a basic->baja calidad

				//pido datos de tarjeta del usuario premium y lo pongo en constructor
				//BASIC*cambiado=new 
			}
			cambiado->setTarjeta();
			*m_Usuarios + cambiado;
			//BASIC* cambiado = new BASIC(*user, 0);//tendriamos que pedir datos de una tarjeta!!!
		}
		else if (tipo == premium && t!=2)
		{
			PREMIUM* cambiado = new PREMIUM(*user);
			cambiado->setCalidad();
			user->setEliminado(true);
			if (t == 0) {
				cambiado->setTarjeta();
			}//no olvidar de mejorar la calidad a 1080!!->llamar a funicion de audiovisual MejorarCalidad
			*m_Usuarios + cambiado;
		}
		else
		{
			throw exception("Ese tipo no se encuentra disponible o ya sos el tipo de usuario");//ya es de ese tipo
		}
	}

}


