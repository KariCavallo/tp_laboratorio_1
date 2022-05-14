#include "EstadoVuelo.h"
#include <stdio.h>
#include <stdlib.h>

int cargarDescripcionEstado(Estado estados[], int tame, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarEstado(estados,tame, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, estados[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarEstado(Estado estados[], int tame, int id, int* pIndice){
    int todoOk = 0;
    if(estados != NULL && tame > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tame; i++){

                if(estados[i].id == id){

                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
