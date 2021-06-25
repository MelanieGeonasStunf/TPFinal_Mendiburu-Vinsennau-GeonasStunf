#include "FREE.h"
#include "Plataforma.h"


FREE::FREE(int Edad, Paises Pais, string Password, const string Name,string* tarjeta):
	Usuarios(Edad, Pais, Password, Name, false, tarjeta)
{
	tiempoConex = 0;
	//int contador = 0;
	primeringreso = { 0,0,0 };
	contadorsem = 0;
	//ServAElegir = new Servicios*[10];
}



FREE::~FREE(){

}

FREE::FREE(Usuarios& user):Usuarios(user)
{
	tiempoConex = 0;
	//int contador = 0;
	primeringreso = { 0,0,0 };
	contadorsem = 0;
}





void FREE::Anuncios(){
//imprimimos algo en la pantalla?
	cout << "\n\n\nQUIERE CAMBIARSE DE PLAN?" << endl;
	cout << "\nPor tan solo $200 puede ser un usuario BASIC con ilimitados minutos de reproduccion" << endl;
	cout << "\nO por $300 un usuario PREMIUM con opcion de DESCARGAR videos!!" << endl;

}


tm FREE::LimiteTiempoMax = { 00,00,15 };
void FREE::LimiteTiempo(){	
	//Solo puede usar cualquier servicio 15 horas por SEMANA!-> contamos el tiempo de conexion
		

}



cListaT<Servicios>* FREE::VariarLista(cListaT<Servicios>* serv){
//el usuario free puede elegir entre 10 servicios aleatorios de la plataforma
	cout << "SERVICIOS A ELEGIR: " << endl;
	int cont = 0;
	cListaT<Servicios>* ServAElegir=new cListaT<Servicios>();
for (int i=0;i<10;i++)
{

	int nro = rand() % serv->getCA();
	if(dynamic_cast<Juegos*>(serv->vector[i])!=NULL)
	{
		cout << "OPCION " << i << ": Juego: " << serv->vector[i]->getNombre() << endl;
		ServAElegir->vector[cont] = serv->vector[i];
	}
	if(dynamic_cast<Audio*>(serv->vector[i])!=NULL)
	{
		cout << "OPCION " << i << ": Audio: " << serv->vector[i]->getNombre() << endl;
		ServAElegir->vector[cont] = serv->vector[i];

	}
	if(dynamic_cast<AudioVisual*>(serv->vector[i])!=NULL)
	{
		cout << "OPCION " << i << ": Videos: " << serv->vector[i]->getNombre() << endl;
		ServAElegir->vector[cont] = serv->vector[i];
	}
	cont++;
}
return ServAElegir;
}


void FREE::Registrarse(Plataforma* plataforma){
	if (this == NULL)
		throw new exception("\nNo se pudo registrar el usuario ingresado.");
	try {
		if ((plataforma->m_Usuarios->BuscarItem1(UserName)) != -1)
			throw new exception("\nEl nombre de usuario ingresado ya posee una cuenta");//en este caso el usuario ya esta registrado
	}
	catch (exception* e)
	{
		cout << e->what();
	}
	*(plataforma->m_Usuarios) + this;
	Estado = true;//se inicia sesion
	setFHinicio();
	cListaT<RegUsuarios>* RegU = plataforma->getRgUsuarios();
	*RegU + RegistrarenRegistro();
	cantConexSemana++;
}

void FREE::SeleccionarServicio(cListaT<Servicios>* serv)
{
	cListaT<Servicios>* aElegir=VariarLista(serv);
	//int pos = rand() % 10;
	int pos = 1;
	if(tiempoConex>54000)
		throw new exception("\nHa superado su limite semanal.");
	if ((*aElegir)[pos] != NULL)
	{
		Juegos* aux = dynamic_cast<Juegos*>((*aElegir)[pos]);
		if (aux!=NULL)
		{
			servicio = new Juegos(*aux);
		}
		AudioVisual* aux1 = dynamic_cast<AudioVisual*>((*aElegir)[pos]);
		if (aux1!=NULL)
		{
			servicio = new AudioVisual(*aux1);
		}
		Audio* aux2 = dynamic_cast<Audio*>((*aElegir)[pos]);
		if (aux2!=NULL)
		{
			servicio = new Audio(*aux2);
		}
		
		try
		{
			servicio->VerificarPais(this);
		}
		catch (exception* e)
		{
			throw e;
		}
		int rangoEtareo = servicio->ChequearEdad();
		if (Edad < 13 && rangoEtareo != 0)
		{
			throw exception("No tiene la edad suficiente para utilizar este servicio");
		}
		if (Edad < 18 && rangoEtareo == 2)
		{
			throw exception("No tiene la edad suficiente para utilizar este servicio");
		}
	}
	//si la edad>18 no tiene ninguna restriccion

}

void FREE::settiempoConex()
{
	FechayHoraInicio.tm_year = (FechayHoraInicio).tm_year - 1900;
	FechayHoraCierre.tm_year = (FechayHoraCierre).tm_year - 1900;
	time_t i = mktime(&FechayHoraInicio);
	time_t f = mktime(&FechayHoraCierre);
	long int tiempo = difftime(f, i);
	tiempoConex = tiempoConex + tiempo;
}
void FREE::tiempoExcedido()
{
	if (tiempoConex > 54000)
	{
		cout << "\n Se ha excedido del tiempo limte, ingrese el numero de su tarjeta de credito para cubrir los gastos extra."<<endl;
		setTarjeta();
		throw new exception("\nDebe salir de la plataforma.");
	}
}