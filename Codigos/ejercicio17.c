#include <stdio.h>
#include "ejercicios.h"

void ejercicio17() {
    int numero;

    do {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    } while (numero >= 0);

    printf("Se ingreso un numero negativo. Fin del programa.\n");
}