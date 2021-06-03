#pragma once

void Crear_Archivo();//Crea archivo vacion--> TIRA EXCEPCION 

template <class T>
int LeerArchivo(cListaT <T> * lista);

template <class T>
void GuardarArchivo(cListaT <T>* lista, int n);

int cant_registro();
