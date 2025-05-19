#include <stdio.h>
#include "ejercicios.h"

void ejercicio13() {
    float nota;
    do {
        printf("Ingrese una nota entre 0 y 10: ");
        scanf("%f", &nota);
    } while (nota < 0 || nota > 10);

    printf("Nota valida ingresada: %.2f\n", nota);
}