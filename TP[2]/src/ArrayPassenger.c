#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassenger.h"
#include "EstadoVuelo.h"



int menu(){

    int opcion;

    printf("  *** Menu de Opciones ***\n\n");
    printf("1- Altas\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Carga forzada de datos\n");
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    miCls();

    return opcion;
}

void miCls(){

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}

void confimarSalida(char* p)
{

    char confiarma;
    printf("Confiarma salida?: ");
    fflush(stdin);
    scanf("%c", &confiarma);

    *p= confiarma;
}

int inicializarPasajaros(Pasajero* lista, int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarPasajeroLibre(Pasajero vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarPasajero(Pasajero vec[], int tam, int* pId)
{
    int todoOk = 0;
    int indice;
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoDeVuelo[10];
    int tipoDePasajero;
    int estadoVuelo;
    int id;


    if(vec != NULL && tam > 0 && pId != NULL)
    {
        if( buscarPasajeroLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {

                printf("Ingrese el nombre del pasajero: ");
                fflush(stdin);
                gets(nombre);

                while(strlen(nombre) >= 51)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(nombre);
                }


                printf("Ingrese el apellido del pasajero: ");
                fflush(stdin);
                gets(apellido);

                while(strlen(apellido) >= 51)
                {
                    printf("Apellido demasiado largo. Reingrese apellido: ");
                    fflush(stdin);
                    gets(apellido);
                }



                printf("Ingrese precio: ");
                scanf("%f", &precio);

                while(precio <1){


                printf("Error, reingrese precio: ");
                scanf("%f", &precio);

                }

                printf("Ingrese el codigo de vuelo: ");
                fflush(stdin);
                gets(codigoDeVuelo);

                while(strlen(codigoDeVuelo) >= 10){

                printf("Error, reingrese el codigo de vuelo: ");
                fflush(stdin);
                gets(codigoDeVuelo);
                }

                printf("Ingrese el tipo de pasajero:... 1 para PRIMERA CLASE / 2 para EJECUTIVO / 3 para TURISTA ");
                scanf("%d", &tipoDePasajero);

                while(tipoDePasajero < 1 && tipoDePasajero >3){

                printf("Error, Reingrese el tipo de pasajero:... 1 para PRIMERA CLASE / 2 para EJECUTIVO / 3 para TURISTA ");
                scanf("%d", &tipoDePasajero);
                }


                printf("Ingrese el Estado de vuelo:... 1 para ACTIVO / 2 para INACTIVO ");
                scanf("%d", &estadoVuelo);

                while(estadoVuelo != 1 && estadoVuelo != 2){

                printf("Error, reingrese el Estado de vuelo:... 1 para ACTIVO / 2 para INACTIVO ");
                scanf("%d", &estadoVuelo);

                }




                id = *pId;
                *pId = *pId + 1;

                agregarPasajero(vec, tam, id, nombre ,apellido, precio, tipoDePasajero,estadoVuelo, codigoDeVuelo, indice);

                todoOk = 1;


            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    return todoOk;
}

int agregarPasajero(Pasajero* lista, int tam, int id, char nombre[],char apellido[],float precio,int tipoDePasajero, int estadoVuelo, char codigoDeVuelo[], int indice)
{
        Pasajero nuevoPasajero;

        nuevoPasajero.id = id;
        strcpy(nuevoPasajero.nombre, nombre);
        strcpy(nuevoPasajero.apellido, apellido);
        nuevoPasajero.precio = precio;
        nuevoPasajero.tipoDePasajero = tipoDePasajero;
        nuevoPasajero.idEstadoVuelo = estadoVuelo;
        strcpy(nuevoPasajero.codigoDeVuelo, codigoDeVuelo);
        nuevoPasajero.isEmpty = 0;

        lista[indice] = nuevoPasajero;



        //printf("%s %s %f %d %s %d",lista[indice].nombre,lista[indice].apellido,lista[indice].precio,lista[indice].tipoDePasajero,lista[indice].codigoDeVuelo,lista[indice].isEmpty);

        return -1;



}

int encontrarPasajeroPorID(Pasajero* lista, int tam,int id)
{
    int flag = 0;


    if(lista != NULL && tam > 0 && id > 0)
    {
        for(int i = 0; i < tam; i++){

            if(lista[i].id == id)
            {
                return i;


            }
            flag = 1;
        }

    }

    if(flag){
        return NULL;
    }

    return -1;

}

int removerPasajero(Pasajero* lista, int tam, int id)
{

    int Id;

        printf("Ingrese el Id del pasajero que desea dar de baja: ");
        scanf("%d", &id);
        int indice = encontrarPasajeroPorID(lista,tam,id);

        if(indice == NULL){

                //"No se encontro un pasajero con ese id."

        }
        else if(indice == -1){

                //"Datos ingresados erroneos."

        }
        else{
            lista[indice].isEmpty = 1;
            //"Pasajero eliminado correctamente!."
        }

        return -1;
}


int mostrarPasajeros(Pasajero* lista, int tam, Estado estados[],int tame)
{
    char tipo[51] = "";
    char descEstado[20] = "";




    //cargarDescripcionEstado( estados, tame,  lista->idEstadoVuelo, descEstado);





            printf("          *** Listado de Pasajeros ***\n\n");
            printf(" Id          Nombre        Apellido        Precio       Tipo De Pasajero    Estado de Vuelo    Codigo De Vuelo\n");
            printf("---------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < tam; i++)
    {


       if(lista[i].isEmpty == 0)
        {
            cargarDescripcionEstado( estados, tame,  lista[i].idEstadoVuelo, descEstado);
            //printf("puto el que lee");
            if(lista[i].tipoDePasajero == 1){
                strcpy(tipo,"PRIMERA CLASE");
            }
            else if(lista[i].tipoDePasajero == 2)
            {
                strcpy(tipo,"EJECUTIVO    ");

            }
            else{
                strcpy(tipo,"TURISTA      ");
            }


            printf("%d             %s          %s         %2.f          %s      %s     %s \n",lista[i].id,lista[i].nombre, lista[i].apellido, lista[i].precio, tipo,descEstado, lista[i].codigoDeVuelo);




        }
    }

    return 0;
}

int ordenarPasajeros(Pasajero* lista, int tam,Estado estados[], int tame, int orden)
{

    if(orden == 1)
    {
        ordenoApellidoYTipoAsc(lista,tam, estados, tame);

    }
    if(orden == 2)
    {

        ordenoApellidoYTipoDesc(lista,tam, estados, tame);
    }

    if(orden == 3){

        ordenoCodigoDeVueloActivoAsc( lista,tam,  estados, tame);
    }

    if(orden == 4){

        ordenoCodigoDeVueloActivoDes(lista, tam,  estados,  tame);

    }


}

int ordenoApellidoYTipoAsc(Pasajero* lista, int tam, Estado estados[], int tame)
{

    int todoOk = 0;

    Pasajero auxPasajero;

    Pasajero listaAux[tam];

    for(int i = 0; i < tam; i++ ){

        listaAux[i] = lista[i];

    }



    if(listaAux != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(listaAux[i].tipoDePasajero > listaAux[j].tipoDePasajero )
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }



        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(strcmp(listaAux[i].apellido, listaAux[j].apellido) > 0 && listaAux[i].tipoDePasajero == listaAux[j].tipoDePasajero)
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
        mostrarPasajeros( listaAux, tam, estados,tame);

    }

    return todoOk;

}

int ordenoApellidoYTipoDesc(Pasajero* lista, int tam, Estado estados[], int tame)
{

    int todoOk = 0;

    Pasajero auxPasajero;

    Pasajero listaAux[tam];

    for(int i = 0; i < tam; i++ ){

        listaAux[i] = lista[i];

    }



    if(listaAux != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(listaAux[i].tipoDePasajero < listaAux[j].tipoDePasajero )
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }



        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(strcmp(listaAux[i].apellido, listaAux[j].apellido) < 0 && listaAux[i].tipoDePasajero == listaAux[j].tipoDePasajero)
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
        mostrarPasajeros(listaAux,tam, estados,tame);
    }

    return todoOk;

}

int informarPromedioPrecio(Pasajero vec[], int tam)
{

    int todoOk = 0;
    float acumPrecio = 0;
    int contPasajeros = 0;
    float promedio = 0;
    int contPasajerosPrecioPromedio = 0;

    if(vec != NULL && tam > 0 )
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                acumPrecio += vec[i].precio;
                contPasajeros++;

        }

        }

        if(contPasajeros > 0)
        {
            promedio = acumPrecio / contPasajeros;
        }

        for(int i = 0; i < tam; i ++){

            if(vec[i].precio > promedio){

                contPasajerosPrecioPromedio++;
            }
        }

         miCls();

        printf("    *** Informe Promedio Precio   ***\n\n");
        printf("El total del valor de todos los vuelos es: %2.f, su Promedio es: $ %.2f\n y la cantidad de pasajeros que superan el precio promedio son: %d\n",acumPrecio, promedio, contPasajerosPrecioPromedio);

        todoOk = 1;
    }


    return todoOk;

    }


int menuInformar(){
int opcion;

    printf("  *** Elija la opcion deseada ***\n\n");
    printf("1- Ordenar los pasajeros por apellido y tipo de pasajero de manera asendente\n");
    printf("2- Ordenar los pasajeros por apellido y tipo de pasajero de manera desendiente\n");
    printf("3- Promedio\n");
    printf("4- Ordenar los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ de manera asendente\n");
    printf("5- Ordenar los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ de manera desendente\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    miCls();

    return opcion;
}

int modificarPasajero(Pasajero vec[], int tam, Estado estados[], int tame)
{
    int todoOk = 0;
    int id;
    int indice;
    char salir = 'n';
    char auxCad[100];

    if(vec != NULL && tam > 0)
    {
        miCls();
        mostrarPasajeros(vec, tam, estados,tame);
        printf("Ingrese el id del pasajero que desea modificar: ");
        scanf("%d", &id);

        indice = encontrarPasajeroPorID(vec,tam,id);


        if( indice > -1)
        {


            //indice = encontrarPasajeroPorID(vec,tam,id);


            if(indice == -1)
            {
                printf("No hay un pasajero con Id %d\n", id);
            }
            else
            {
                 mostrarPasajeros(vec, tam, estados,tame);


                do
                {
                    switch(menuModificarPasajero())
                    {

                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(vec[indice].nombre, auxCad);
                        printf("Se ha modificado el nombre\n");
                        break;

                    case 2:
                           printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(vec[indice].apellido, auxCad);
                        printf("Se ha modificado el apellido\n");
                        break;

                    case 3:
                        printf("Ingrese nueva precio: ");
                        scanf("%f", &vec[indice].precio);
                        printf("Se ha modificado el precio\n");
                        break;

                        break;
                    case 4:
                        printf("Ingrese nuevo tipo de pasajero:  1 para PRIMERA CLASE / 2 para EJECUTIVO / 3 para TURISTA");
                        scanf("%d", &vec[indice].tipoDePasajero);
                        printf("Se ha modificado el tipo de pasajero\n");

                        break;
                    case 5:
                        printf("Ingrese nuevo codigo de vuelo : ");
                        scanf("%s", &vec[indice].codigoDeVuelo);

                        break;
                    case 6:
                        salir = 's';
                        break;

                    default:
					printf("Opcion invalida!\n");

				}
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar el pasajero\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int menuModificarPasajero()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Precio\n");
    printf("4- Tipo de pasajero\n");
    printf("5- Codigo de vuelo\n");
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int ordenoCodigoDeVueloActivoAsc(Pasajero* lista, int tam, Estado estados[], int tame)
{

     int todoOk = 0;

    Pasajero auxPasajero;

    Pasajero listaAux[tam];

    for(int i = 0; i < tam; i++ ){

        listaAux[i] = lista[i];

    }



    if(listaAux != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(listaAux[i].idEstadoVuelo > listaAux[j].idEstadoVuelo)
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }



        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(strcmp(listaAux[i].codigoDeVuelo, listaAux[j].codigoDeVuelo) > 0 && listaAux[i].idEstadoVuelo == listaAux[j].idEstadoVuelo)
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
        mostrarPasajeros( listaAux, tam, estados,tame);

    }

    return todoOk;

}
int ordenoCodigoDeVueloActivoDes(Pasajero* lista, int tam, Estado estados[], int tame)
{

     int todoOk = 0;

    Pasajero auxPasajero;

    Pasajero listaAux[tam];

    for(int i = 0; i < tam; i++ ){

        listaAux[i] = lista[i];

    }



    if(listaAux != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(listaAux[i].idEstadoVuelo > listaAux[j].idEstadoVuelo)
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }



        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(strcmp(listaAux[i].codigoDeVuelo, listaAux[j].codigoDeVuelo) < 0 && listaAux[i].idEstadoVuelo == listaAux[j].idEstadoVuelo)
                {
                    auxPasajero = listaAux[i];
                    listaAux[i] = listaAux[j];
                    listaAux[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
        mostrarPasajeros( listaAux, tam, estados,tame);

    }

    return todoOk;

}

int hardcodearPasajeros(Pasajero vec[], int tam, int cant, int* pId)
{

    int todoOk = 0;
    Pasajero impostores[] =
    {
        {0, "Juan", "Perez", 3000, "lkjh",1,1,0},
        {0, "Daniela", "Fernandez", 2300, "wert",2,2,0},
        {0, "Lucia", "Dominguez", 2000, "mnbh",1,1,0},
        {0, "Mauro", "Zanardo", 2700, "yubv",3,1,0},
        {0, "Diego", "Rebuffo", 2700, "asde",2,1,0},
        {0, "Juana", "Lopez", 3000, "lvjh",1,2,0},
        {0, "Miguel", "Rodriguez", 23, "rbvs",3,1,0},
        {0, "Luciano", "Bruno", 2100, "bhgd",2,2,0},
        {0, "Marina", "Corda", 2700, "frhd",1,1,0},
        {0, "Dalma", "Maceri", 2400, "fgyh",1,2,0}
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;

}

