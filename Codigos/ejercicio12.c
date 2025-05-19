#include <stdio.h>
#include "ejercicios.h"

void ejercicio12() {
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("El numero es par.\n");
    } else {
        printf("El numero es impar.\n");
    }
}
