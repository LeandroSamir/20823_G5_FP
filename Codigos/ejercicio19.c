#include <stdio.h>
#include <string.h>
#include "ejercicios.h"

void ejercicio19() {
    char contra[] = "Programacion";
    char intento[50];

    printf("Ingrese la clave: ");
    scanf("%s", intento);

    while (strcmp(contra, intento) != 0) {
        printf("Clave incorrecta, intente de nuevo: ");
        scanf("%s", intento);
    }

    printf("Clave correcta");
}
