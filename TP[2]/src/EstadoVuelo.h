#ifndef ESTADOVUELO_H_INCLUDED
#define ESTADOVUELO_H_INCLUDED



struct
{
int id;
char descripcion[20];

}typedef Estado;


#endif // ESTADOVUELO_H_INCLUDED


int cargarDescripcionEstado(Estado estados[], int tame, int id, char descripcion[]);

int buscarEstado(Estado estados[], int tame, int id, int* pIndice);
