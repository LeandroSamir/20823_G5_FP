#include <stdio.h>
#include "ejercicios.h"

void ejercicio16() {
  int i, suma;

    suma = 0; // Inicializar suma en 0

    for (i = 1; i <= 10; i++) {
        suma += i; // Sumar i a suma
    }

    printf("La suma de los 10 primeros numeros naturales es: %d\n", suma);
}