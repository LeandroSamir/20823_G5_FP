#include <stdio.h>
#include "ejercicios.h"

void ejercicio11() {
    int edad;
    printf("Ingrese la edad: ");
    scanf("%d", &edad);

    if (edad >= 18) {
        printf("Es mayor de edad.\n");
    }
}
