#include "AudioVisual.h"
#include "RegistroAyV.h"
#include "funciones.h"
#include "Usuarios.h"
class Usuarios;

AudioVisual::AudioVisual(const string clave, const string nombre, int cantP, 
	Paises* paises, RangoEtareo rango, tm duracion)
	:Servicios( clave, nombre, cantP, paises,rango)
{
	this->tiempoInicio = { 0,0,0 };
	this->duracion = duracion;
	cantVisxPer = 0;
}

AudioVisual::AudioVisual(AudioVisual& ayv):Servicios(ayv),
duracion(ayv.duracion)
{
}

AudioVisual::~AudioVisual(){

}





bool AudioVisual::FastBackward(long int& time,long int& TiempoR){
	long int TiempRep = TiempoR - time;
	/*long int dur = duracion.tm_hour * 3600 + duracion.tm_min * 60 + duracion.tm_sec;
	long int faltante = dur - TiempRep;*/
	if (TiempRep < 10) {
		time = time - TiempRep;
		return false;
	}
	time -= 10;
	TiempoR -= 10;
	return true;
}


bool AudioVisual::FastForward(long int& time,long int&TiempoR){

	long int TiempRep = TiempoR - time;
	long int dur = duracion.tm_hour * 3600 + duracion.tm_min * 60 + duracion.tm_sec;
	long int faltante = dur - TiempRep;
	if (faltante < 10)
		return false;
	time += 10;
	TiempoR += 10;
	return true;
	//tiempo es el tiempo que quiere hacer fast forward.
	/*int seg = difftime(0, mktime(&tiempo));//chequear si funciona
	//float min = seg * 60;
	int seg2 = difftime(0, mktime(&duracion));

	if (seg > seg2)
	{
		//hace fast forward de todo el video

	}
*/
	

}


void AudioVisual::Record(){
	cout << "\nGrabacion en progreso." << endl;
}

bool AudioVisual::GuardartiempoRep( int seg)
{
	//int seg = rand() % duracion.tm_sec;
	//int min = rand() % duracion.tm_min;
	long int durSeg = PasarAseg(duracion);
	if (0.3 * durSeg >= seg)
		return true;
	return false;
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
	*/
}


void AudioVisual::IniciarServicio()
{
	tiempoInicio = setLocalTime();
}

RegistroAyV* AudioVisual::RegistrarenRegistro(Usuarios* user,bool visto)
{
	RegistroAyV* reg;
	reg = new RegistroAyV(Nombre, user->getclave(),visto);
	return reg;
}
 ostream& AudioVisual::operator<<(ostream& out)
  {
	 Servicios& P = *this;
	  out << &P<< "\nDuracion: " << to_string(duracion.tm_hour) << ":"
		  << to_string(duracion.tm_min) << ":"<<to_string(duracion.tm_sec) << endl;
	  return out;
  }