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


void Plataforma::EstadisticasPorContenido(){

}


cListaT<Audio>* Plataforma::MasEscuchados(tm Periodo){

	return  NULL;
}


cListaT<Juegos>* Plataforma::MasJugados(tm FechaI, tm FechaF){

int cantJuegos=RegJ->getCA();
Juegos* masJug = Juegos[5];

for(int i=0;i<cantJuegos;i++)
{
//me fijo que el juego se haya jugado en el periodo de tiempo pedido
if(RegJ->vector[i]->getFechaUltJ.tm_year>=FechaI.tm_year && RegJ->vector[i]->getFechaUltJ().tm_year<=FechaF.tm_year)
{
	//tiene anio distinto y tenemos que comparar el mes
	if(RegJ->vector[i]->getFechaUltJ.tm_mon>=FechaI.tm_mon && RegJ->vector[i]->getFechaUltJ().tm_mon<=FechaF.tm_mon)
	{
		//tienen distinto mes, tenemos que comparar el dia
			if(RegJ->vector[i]->getFechaUltJ.tm_mday=>FechaI.tm_mday && RegJ->vector[i]->getFechaUltJ().tm_mday<=FechaF.tm_mday)
			{
					//tienen distino dia, comparamos las horas
	
				if(RegJ->vector[i]->getFechaUltJ.tm_hour=>FechaI.tm_hour && RegJ->vector[i]->getFechaUltJ().tm_hour<=FechaF.tm_hour)
				{
					//tienen hora distinta, me fijo los minutos
					if(RegJ->vector[i]->getFechaUltJ.tm_min=>FechaI.tm_min && RegJ->vector[i]->getFechaUltJ().tm_min<=FechaF.tm_min)
					{
						//tienen minutos distinto me fijo los segundos
						if(RegJ->vector[i]->getFechaUltJ.tm_sec>=FechaI.tm_sec && RegJ->vector[i]->getFechaUltJ().tm_sec<=FechaF.tm_sec)
						{
							//si entra, significa que esta en el periodo de tiempo pedido
						}

					}
				}
			}
	
	}	
}

	//significa que no esta entre el periodo de anios pedido



	return  NULL;
}


cListaT<AudioVisual>* Plataforma::MasVistos(tm Periodo){

	return  NULL;
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


