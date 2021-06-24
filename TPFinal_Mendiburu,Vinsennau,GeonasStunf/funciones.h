#pragma once
#include "Plataforma.h"
#include "Librerias.h"


bool tick();
//cuenta para saber cuantos dias pasaron de la semana->para cortar el main cuando se termina la semana

string Encriptar(string clave);//encripta claves y nros de tarjeta
int Menu1();
int Menu2();
long int PasarAseg(tm tiempo);
//menu cambiar a int?
/*
1. Iniciar sesion -> cambia estado a conectado y vuelve a menu principal
2. Cerrar sesion -> cambia estado a desconectado y termina el loop
3. Registrarse -> se registra y vuelve al menu principal
4. Eliminar cuenta -> se elimina y vuelve al menu principal
5. Seleccionar Servicio -> Verifica si esta registrado y si le pertenece el servicio que selecciono
*/
void Casos1(Usuarios*user, Plataforma* plataforma);// recibe opcion del menu-> tira un throw
void Casos2(Usuarios* user, Plataforma* plataforma);

tm setLocalTime();