///////////////////////////////////////////////////////////
//  RegistroAyV.h
//  Implementation of the Class RegistroAyV
//  Created on:      01-Jun-2021 10:50:21 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#if !defined(EA_AE23B68B_B092_4f8f_A892_F3C0E0DFA130__INCLUDED_)
#define EA_AE23B68B_B092_4f8f_A892_F3C0E0DFA130__INCLUDED_

#include "AudioVisual.h"
#include "Audio.h"
#include "Librerias.h"

class RegistroAyV
{

public:
	RegistroAyV();
	virtual ~RegistroAyV();
	AudioVisual *m_AudioVisual;
	Audio *m_Audio;

private:
	tm Fecha;
	int ListadeRecientes;
	int MinutodeReproduccion;
	const string UserName;

};
#endif // !defined(EA_AE23B68B_B092_4f8f_A892_F3C0E0DFA130__INCLUDED_)
