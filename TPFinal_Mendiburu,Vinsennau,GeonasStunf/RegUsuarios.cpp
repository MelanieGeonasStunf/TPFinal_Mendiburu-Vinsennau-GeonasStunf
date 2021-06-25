#include "RegUsuarios.h"

int RegUsuarios::counter = 0;

RegUsuarios::RegUsuarios(const string Name, int TipoUsuario):UserName(Name), clave(to_string(counter))
{
	counter++;
	this->TipoUsuario = TipoUsuario;
}

RegUsuarios::~RegUsuarios(){

}





void RegUsuarios::BuscarTipoUsuario(){

}