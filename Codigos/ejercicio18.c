#include <stdio.h>
#include "ejercicios.h"

void ejercicio18() {
	int x;
	printf("Numeros pares entre 1 y 10\n");
	for (x=1 ; x<=10; x++){
		if ((x%2)==0){
			printf("%i ",x);
		}
	}
}