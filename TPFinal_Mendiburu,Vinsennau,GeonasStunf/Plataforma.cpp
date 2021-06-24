#include "Plataforma.h"
#include "FREE.h"
#include "BASIC.h"
#include "PREMIUM.h"

Plataforma::Plataforma():Nombre("Labflix")
{
	this->CantidadUsuariosConectados=0;
	//ListaUsuariosxDia = new cListaT<Usuarios>;
	this-> UsuariosxSemana=0;
	m_Servicios=NULL;
	m_Usuarios=NULL;
	
	paises=new Paises[14]{Argentina, Chile,	Peru, Brasil, Colombia,	Mexico,	EstadosUnidos,
	Canada,Bolivia,	Paraguay,	Uruguay,	Venezuela,	España,	Francia};
}

Plataforma::~Plataforma(){
	//delete ListaUsuariosxDia;
	delete m_Usuarios;
	delete m_Servicios;
}


void Plataforma::EstadisticasPorContenido(Servicios*serv){

}


cListaT<Audio>* Plataforma::MasEscuchados(tm FechaI, tm FechaF){

	return  NULL;
}


string* Plataforma::MasJugados(tm FechaI, tm FechaF) {

	int cantJuegos = RegJ->getCA();
	//cListaT<Juegos>* masJug = new cListaT<Juegos>(5);//solo nos fijamos los 5 mas jugados
	string* masJug = new string[3];
	int mJ=-1;
	int mJ2 = -1;
	int mJ1 = -1;

	int cont = 0;//cuenta cuantos juegos estan dentro del periodo pedido
	cListaT<RegistroJuegos>* JugadosEnPeriodo;

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


cListaT<AudioVisual>* Plataforma::MasVistos(tm FechaI, tm FechaF)
{

	int cantVideos = RegAyV->getCA();
	//cListaT<Juegos>* masJug = new cListaT<Juegos>(5);//solo nos fijamos los 5 mas jugados
	string* masVis = new string[3];
	int mV = -1;
	int mV2 = -1;
	int mV1 = -1;

	int cont = 0;//cuenta cuantos juegos estan dentro del periodo pedido
	cListaT<RegistroAyV>* VistosEnPeriodo;

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
				Juegos* ju = dynamic_cast<Juegos*>(m_Servicios->vector[j]);
				if (ju != NULL)
				{
					if (VistosEnPeriodo->vector[i]->getNombre() == ju->getNombre())
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

		return  masJug;
}

void Plataforma::PromedioConectadosenSemanaxDia()
{
	int cant = UsuariosxSemana / 7;
}

void Plataforma::VerResumen(){
	//imprimimos todo :)
}

void Plataforma::EditarCuenta(Usuarios* user, int tipo, bool eliminar)
{	/*
	* 2 OPCIONES:
	* -Eliminar Cuenta.
	* -Cambiar tipo usuario.
	*/
	int t;
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
			if (tipo == 2)//significa que era premium 
			{
				//de premium a free->baja calidad
			}
		}
		else if (tipo == basic && t!=1)
		{
			if (tipo == 2)//significa que era premium y ya tengo datos de una tarjeta.
			{
				//de premium a basic->baja calidad

				//pido datos de tarjeta del usuario premium y lo pongo en constructor
				//BASIC*cambiado=new 
			}
			//BASIC* cambiado = new BASIC(*user, 0);//tendriamos que pedir datos de una tarjeta!!!
		}
		else if (tipo == premium && t!=2)
		{
			//no olvidar de mejorar la calidad a 1080!!->llamar a funicion de audiovisual MejorarCalidad
		}
		else
		{
			throw exception("Ese tipo no se encuentra disponible o ya sos el tipo de usuario");//ya es de ese tipo
		}
	}

}


