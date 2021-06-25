#include "Audio.h"
#include "RegistroAyV.h"
#include "funciones.h"
#include "Usuarios.h"

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



bool Audio::FastBackward(long int& time,long int&TiempoR){
	long int TiempRep = TiempoR - time;
	if (TiempRep < 10) {
		time = time - TiempRep;
		return false;
	}
	time -= 10;
	TiempoR -= 10;
	return true;
}


bool Audio::FastForward(long int& time,long int&TiempoR){
	long int TiempRep = TiempoR - time;
	long int dur = duracion.tm_hour * 3600 + duracion.tm_min * 60 + duracion.tm_sec;
	long int faltante = dur - TiempRep;
	if (faltante < 10)
		return false;
	time += 10;
	TiempoR += 10;
	return true;
}


void Audio::Record(){
	cout << "\nGrabacion en progreso." << endl;
}



bool Audio::GuardartiempoRep( int seg)
{
	long int durSeg = PasarAseg(duracion);
	if (0.3 * durSeg >= seg)
		return true;

	return false;
}



RegistroAyV* Audio::RegistrarenRegistro(Usuarios* user,bool visto) //no se si hay que pasarle el tiempo de reproduccion
{
	RegistroAyV* reg;
	reg = new RegistroAyV(Nombre, user->getclave(),visto);
	return reg;
}
 ostream& Audio::operator<<(ostream& out)
  {
	 Servicios& P = *this;
	 out << &P << "\nDuracion: " << to_string(duracion.tm_hour) << ":"
		 << to_string(duracion.tm_min) << ":" << to_string(duracion.tm_sec) << endl;
	 return out;
  }