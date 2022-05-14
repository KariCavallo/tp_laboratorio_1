#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "EstadoVuelo.h"


#define TAM 2000
#define TAME 2


int menu();

int main()
{
 setbut(stdout,NULL);

    Pasajero listaDePasajero[TAM];


	 char salir = 'n';
	 int Id = 1;

	  Estado estados[TAME] =
    {
        {1, "Activo"},
        {2, "Inactivo"}
    };

	 inicializarPasajaros(listaDePasajero, TAM);



	do{

		 miCls();

		switch(menu())
				{
				case 1:


                        cargarPasajero(listaDePasajero, TAM, &Id);


					break;

				case 2:


                    modificarPasajero(listaDePasajero, TAM, estados, TAME);

					break;

				case 3:

                        removerPasajero(listaDePasajero, TAM, Id);

					break;

				case 4:

                    switch(menuInformar()){


                                case 1:
                                        ordenarPasajeros(listaDePasajero, TAM, estados, TAME, 1);
                                        break;

                                case 2:
                                        ordenarPasajeros(listaDePasajero, TAM, estados, TAME, 2);
                                        break;

                                case 3:

                                        informarPromedioPrecio(listaDePasajero,TAM);

                                        break;

                                case 4:
                                             ordenarPasajeros(listaDePasajero, TAM, estados, TAME, 3);
                                        break;

                                case 5:

                                    ordenarPasajeros(listaDePasajero, TAM,  estados,  TAME,4);

                                       break;



                    }



					break;
				case 5:

                            hardcodearPasajeros(listaDePasajero, TAM, 10, &Id);
					break;
				case 6:
		            confimarSalida(&salir);

					break;

				default:
					printf("Opcion invalida!\n");

				}

				system("pause");


			}

	while(salir != 's');






    return 0;
}
