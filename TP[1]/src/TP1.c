/*
 ============================================================================
 Name        : TP1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int menu();
void kilometros(int* pFlag);
void aerolinea(int* pFlag);
void calcularCostos(int *pFlag1, int * pFlag2);
void mostrar();
void datosForzados();
void confimarSalida(char* p);

//kilometros()
int kilometrosTotales;

//aerolineas()
float precioAerolineas;
float precioLatam;

//calcularCostos()
float arrayAerolineas [ 4 ];
float arrayLatam [ 4 ];





int main(void) {

	setbuf(stdout,NULL);

	 char salir;
	 int flagKilometros = 0;
	 int flagAerolinea = 0;
	 int flagCalcularCostos = 0;




	do{

		system("cls");

		switch(menu())
				{
				case 1:


					kilometros(&flagKilometros);

					break;

				case 2:



					if(flagKilometros)
					{
						aerolinea(&flagAerolinea);

					 }
					 else
					 {
						 printf("Ingrese la cantidad de kilometros primero!\n");

					 }

					break;

				case 3:

					//calcularCostos(int *pFlag1, int * pFlag2);

					if(flagAerolinea)
					{
						calcularCostos(&flagAerolinea, &flagKilometros);
						flagCalcularCostos = 1;


					 }
					else if (flagKilometros)
					{

						printf("Debe ingresar los kilometros primero!\n");

					}
					else
					{

						printf("Debe seleccionar una aerolinea primero!\n");

					}

					break;

				case 4:
						if (flagCalcularCostos){

							if(flagCalcularCostos)
							{
								mostrar();
							}

						}
						else{

							printf("Debe calcular los costos primero!\n");

							}
					break;
				case 5:
					datosForzados();
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


	return EXIT_SUCCESS;



}

int menu() {

	    int opcion;

	    system("cls");
	    printf("  *** Menu de Opciones ***\n\n");
	    printf("1- Kilometros\n");
	    printf("2- Aerolinea deseada\n");
	    printf("3- Calcular costos\n");
	    printf("4- Resultados\n\n");
	    printf("5- Carga foraza de datos\n\n");
	    printf("6- Salir\n\n");
	    printf("Ingrese opcion: ");
	    scanf("%d", &opcion);

	    system("cls");

	    return opcion;
}

void kilometros(int* pFlag) {

	printf("Ingrese la cantidad de kilometros\n");
	fflush(stdin);
	scanf("%d", &kilometrosTotales);
	*pFlag = 1;

}


void aerolinea(int* pFlag) {


	printf("Ingrese precio Aerolineas: \n");
	fflush(stdin);
	scanf("%f", &precioAerolineas);

	printf("Ingrese precio Latam: \n");
	fflush(stdin);
	scanf("%f", &precioLatam);


	*pFlag = 1;

}

void calcularCostos(int *pFlag1, int * pFlag2) {


	arrayAerolineas[0] = precioAerolineas * 0.9;
	arrayAerolineas[1] = precioAerolineas * 1.25;
	arrayAerolineas[2] = precioAerolineas / 4606954.55 ;
	arrayAerolineas[3] = precioAerolineas / kilometrosTotales;

	arrayLatam[0] = precioLatam * 0.9;
	arrayLatam[1] = precioLatam * 1.25;
	arrayLatam[2] = precioLatam / 4606954.55 ;
	arrayLatam[3] = precioLatam / kilometrosTotales;




	 *pFlag1 =0;
	 *pFlag2 =0;

}

void mostrar()
{
	printf("KMs Ingresados: %d Km\n\n",kilometrosTotales);

	printf("Precio Areolineas: $ %.2f\n",precioAerolineas);
	printf("a) Precio con tarjeta de debito: $ %.2f \n", arrayAerolineas[0]);
	printf("b) Precio con tarjeta de credito: $ %.2f \n", arrayAerolineas[1]);
	printf("c) Precio con BTC: %f BTC\n", arrayAerolineas[2]);
	printf("d) Precio unitario: $ %.2f \n\n", arrayAerolineas[3]);


	printf("Precio Latam: $ %.2f\n", precioLatam);
	printf("a) Precio con tarjeta de debito: $ %.2f \n", arrayLatam[0]);
	printf("b) Precio con tarjeta de credito: $ %.2f \n", arrayLatam[1]);
	printf("c) Precio con BTC: %f BTC\n", arrayLatam[2]);
	printf("d) Precio unitario: $ %.2f \n\n", arrayLatam[3]);


	printf("La diferencia de precio es de: $ %.2f \n", precioAerolineas - precioLatam);


}


void datosForzados(){


		kilometrosTotales = 7090;
		precioAerolineas = 162965;
		precioLatam = 159339;

	    arrayAerolineas[0] = precioAerolineas * 0.9;
		arrayAerolineas[1] = precioAerolineas * 1.25;
		arrayAerolineas[2] = precioAerolineas / 4606954.55 ;
		arrayAerolineas[3] = precioAerolineas / kilometrosTotales;

		arrayLatam[0] = precioLatam * 0.9;
		arrayLatam[1] = precioLatam * 1.25;
		arrayLatam[2] = precioLatam / 4606954.55 ;
		arrayLatam[3] = precioLatam / kilometrosTotales;

		mostrar();


}

void confimarSalida(char* p)
{

    char confiarma;
    printf("Confiarma salida?: ");
    fflush(stdin);
    scanf("%c", &confiarma);

    *p= confiarma;
}









