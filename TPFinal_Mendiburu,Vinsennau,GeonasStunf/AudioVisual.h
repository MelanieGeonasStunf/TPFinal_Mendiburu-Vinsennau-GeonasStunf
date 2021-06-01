///////////////////////////////////////////////////////////
//  AudioVisual.h
//  Implementation of the Class AudioVisual
//  Created on:      01-Jun-2021 10:50:04 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_699459EF_0D5E_4b37_9041_0E92694884C5__INCLUDED_)
#define EA_699459EF_0D5E_4b37_9041_0E92694884C5__INCLUDED_

#include "Servicios.h"
#include "Librerias.h"

class AudioVisual : public Servicios
{

public:
	AudioVisual();
	virtual ~AudioVisual();

	void FastBackward();
	void FastForward();
	void Record();
	void VelocidadReproduccion();

private:
	int Calidad;
	int int TipoAudioVisual;

};
#endif // !defined(EA_699459EF_0D5E_4b37_9041_0E92694884C5__INCLUDED_)
