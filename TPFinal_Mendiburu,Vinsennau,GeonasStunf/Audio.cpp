#include "Audio.h"
#include "RegistroAyV.h"
#include "funciones.h"

Audio::Audio(const string clave, const string nombre, int cantP, Paises* paises, RangoEtareo rango, tm duracion)
	:Servicios(clave, nombre, cantP, paises, rango)
{
	this->duracion = duracion;
	this->tiempoInicio = { 0,0,0 };
	cantEscxPer = 0;
}
Audio::Audio(Audio& audio):Servicios(audio), duracion(audio.duracion)
{
}
void Audio::IniciarServicio()
{ 
	tiempoInicio = setLocalTime();
}

Audio::~Audio(){

}





void Audio::FastBackward(long int& time,long int&TiempoR){
	time -= 10;
	TiempoR -= 10;
}


void Audio::FastForward(long int& time,long int&TiempoR){
	time += 10;
	TiempoR += 10;
}


void Audio::Record(){
	cout << "\nGrabacion en progreso." << endl;
}


/*void Audio::VelocidadReproduccion(int velocidad){

}*/


void Audio::GuardartiempoRep(RegistroAyV* reg, int seg)
{
	//int seg = rand() % duracion.tm_sec;
	//int min = rand() % duracion.tm_min;
	long int durSeg = PasarAseg(duracion);
	if (0.3 * durSeg >= seg)
		reg->Visto = true;
	/*int hs = rand() % duracion.tm_hour;
	if (hs == duracion.tm_hour)
	{
		int min = rand() % duracion.tm_min;
		if (min == duracion.tm_min)
		{
			int seg = rand() % duracion.tm_sec;
			//Si el usuario vio mas del 30% -> tomamos como video visto.
			int tiempoRep = hs * 10000 + min * 1000 + seg;
			int tiempoTotal = duracion.tm_hour * 10000 + duracion.tm_min * 1000 + duracion.tm_sec;

			tm tiempoR = { hs, min, seg };
			reg->tiempoReproduccion = tiempoR;

			if (tiempoRep == tiempoTotal * 0.3)
			{
				//significa que vio el 30% del video
				reg->Visto = true;
			}
		}
		return;
	}

	int min = rand() % duracion.tm_min;
	if (min == duracion.tm_min)
	{
		if (min == duracion.tm_min)
		{
			int seg = rand() % duracion.tm_sec;

			int tiempoRep = hs * 10000 + min * 1000 + seg;
			int tiempoTotal = duracion.tm_hour * 10000 + duracion.tm_min * 1000 + duracion.tm_sec;

			tm tiempoR = { hs, min, seg };
			reg->tiempoReproduccion = tiempoR;

			if (tiempoRep == tiempoTotal * 0.3)
			{
				//significa que vio el 30% del video
				reg->Visto = true;
			}
		}

		return;
	}

	int seg = rand() % duracion.tm_sec;
	int tiempoRep = hs * 10000 + min * 1000 + seg;
	int tiempoTotal = duracion.tm_hour * 10000 + duracion.tm_min * 1000 + duracion.tm_sec;

	tm tiempoR = { hs, min, seg };
	reg->tiempoReproduccion = tiempoR;

	if (tiempoRep == tiempoTotal * 0.3)
	{
		//significa que vio el 30% del video
		reg->Visto = true;
	}

}*/

	/*void AudioVisual::IniciarServicio()
	{

		tiempoInicio = setLocalTime();
	}*/





RegistroAyV* Audio::RegistrarenRegistro(Usuarios* user,bool visto) //no se si hay que pasarle el tiempo de reproduccion
{
	RegistroAyV* reg;
	reg = new RegistroAyV(Nombre, user->getclave(),visto);
	return reg;
}
