#pragma once


/*
void crear_archivo1()
{
	FILE* fp = fopen("servicios.dat", "w+b");
	if (fp == NULL)
		throw exception("No se pudo crear el archivo");
	fclose(fp);
}//Crea archivo vacion--> TIRA EXCEPCION 

void crear_archivo2()
{
	FILE* fp = fopen("usuarios.dat", "w+b");
	if (fp == NULL)
		throw exception("No se pudo crear el archivo");
	fclose(fp);
}

template <class T>
int LeerArchivo(cListaT <T>* lista, string archivo)
{

	FILE* fp = fopen("servicios.dat", "rb");
	int i = 0;
	if (fp == NULL)
	{
		//printf("\nSe ha creado el archivo.");
		return 0;
	}
	else
	{
		do
		{
			Emprendedor* aux = new Emprendedor;
			fread(aux, sizeof(Emprendedor), 1, fp);
			lista[i] = aux;
			i++;
		} while (!feof(fp));
		fclose(fp);
		return i - 1;
	}

}

template <class T>
void GuardarArchivo(cListaT <T>* lista, int n, string archivo)
{
	FILE* fp = fopen(archivo, "wb");
	if (fp == NULL) {
		throw exception("\nNo se pudo abrir el archivo");
	}
		
		T* aux = new cListaT<T>(n);

		for (int i = 0; i < n; i++)
			aux[i] = *lista[i];

		fwrite(aux, sizeof(T), n, fp);

	fclose(fp);
	delete aux;
}

template <class T>
int cant_registros (string archivo)
{
	FILE* fp = fopen(archivo, "r+b");
	int cant;
	fseek(fp, 0, SEEK_END);
	long int idx = ftell(fp);
	fclose(fp);
	if(archivo == "servicios.dat")
		cant = idx / sizeof(Servicios);
	if (archivo == "usuarios.dat")
		cant = idx / sizeof(Usuarios);
	else throw exception("No existe ese archivo");

	return cant;
}
*/