#include "RegistroAyV.h"


int RegistroAyV::counter = 0;
RegistroAyV::RegistroAyV(const string Name):UserName(Name),clave(to_string(counter))
{
	counter++;
}

RegistroAyV::~RegistroAyV(){

}