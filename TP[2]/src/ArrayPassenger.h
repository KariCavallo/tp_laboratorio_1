#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED

#include "EstadoVuelo.h"



#endif // ARRAYPASSENGER_H_INCLUDED

struct
{
int id;
char nombre[51];
char apellido[51];
float precio;
char codigoDeVuelo[10];
int tipoDePasajero;
int idEstadoVuelo;
int isEmpty;
}typedef Pasajero;

int menu();

void miCls();

void confimarSalida(char* p);

int inicializarPasajaros(Pasajero* lista, int tam);

int buscarPasajeroLibre(Pasajero vec[], int tam, int* pIndex);

int cargarPasajero(Pasajero vec[], int tam, int* pId);

int agregarPasajero(Pasajero* lista, int tam, int id, char nombre[],char apellido[],float precio,int tipoDePasajero, int estadoVuelo, char codigoDeVuelo[], int indice);

int encontrarPasajeroPorID(Pasajero* lista, int tam,int id);

int removerPasajero(Pasajero* lista, int tam, int id);

int mostrarPasajeros(Pasajero* lista, int tam, Estado estados[],int tame);


int ordenarPasajeros(Pasajero* lista, int tam, Estado estados[], int tame,int orden);

int ordenoApellidoYTipoAsc(Pasajero* lista, int tam, Estado estados[],int tame);

int ordenoApellidoYTipoDesc(Pasajero* lista, int tam, Estado estados[], int tame);

int informarPromedioPrecio(Pasajero vec[], int tam);

int menuInformar();

int menuModificarPasajero();

int modificarPasajero(Pasajero vec[], int tam, Estado estados[], int tame);


int ordenoCodigoDeVueloActivoAsc(Pasajero* lista, int tam, Estado estados[], int tame);

int ordenoCodigoDeVueloActivoDes(Pasajero* lista, int tam, Estado estados[], int tame);


int hardcodearPasajeros(Pasajero vec[], int tam, int cant, int* pId);

