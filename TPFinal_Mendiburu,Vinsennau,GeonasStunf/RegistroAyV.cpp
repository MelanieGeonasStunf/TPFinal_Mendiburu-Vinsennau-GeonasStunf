///////////////////////////////////////////////////////////
//  RegistroAyV.cpp
//  Implementation of the Class RegistroAyV
//  Created on:      01-Jun-2021 10:50:21 AM
//  Original author: gstun
///////////////////////////////////////////////////////////

#include "RegistroAyV.h"



RegistroAyV::RegistroAyV(const string Name):UserName(Name)
{
	ListadeRecientesAyV = NULL;
	for (int i = 0; i < ListadeRecientesAyV->getTAM(); i++)
	{
		ListadeRecientesAyV[i] = NULL;
	}
	ListaRecientesA = NULL;
	for (int i = 0; i < ListaRecientesA->getTAM(); i++)
	{
		ListaRecientesA[i] = NULL;
	}
}

RegistroAyV::~RegistroAyV(){
	delete ListadeRecientesAyV;
	delete ListaRecientesA;
}