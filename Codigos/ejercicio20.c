#include <stdio.h>
#include "ejercicios.h"

void ejercicio20() {
	int contador;
	float x, prom, suma;
	suma=0;

	for (contador=1; contador<=5; contador++){
		printf("Ingrese un numero entero: ");
		scanf("%f",&x);
		suma=suma+x;
	}
	prom=suma/5;
	printf("EL promedio de los numeros ingresados es: %.2f",prom);
}
