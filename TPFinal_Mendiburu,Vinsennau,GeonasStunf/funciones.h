#pragma once
#include "Plataforma.h"
#include "Librerias.h"
#include "Usuarios.h"

bool tick();
//cuenta para saber cuantos dias pasaron de la semana->para cortar el main cuando se termina la semana

void Encriptar(string clave);//encripta claves y nros de tarjeta
void Menu();
/*
1. Iniciar sesion -> cambia estado a conectado y vuelve a menu principal
2. Cerrar sesion -> cambia estado a desconectado y termina el loop
3. Registrarse -> se registra y vuelve al menu principal
4. Eliminar cuenta -> se elimina y vuelve al menu principal
5. Seleccionar Servicio -> Verifica si esta registrado y si le pertenece el servicio que selecciono
*/
void Casos(Usuarios*user, int opcion);// recibe opcion del menu-> tira un throw