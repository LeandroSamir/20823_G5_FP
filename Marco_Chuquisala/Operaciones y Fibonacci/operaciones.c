// operaciones.c
#include <stdio.h>
#include "operaciones.h"

float sumar(float a, float b) {
    return a + b;
}

float restar(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b == 0) {
        printf("Error: Division por cero.\n");
        return 0;
    }
    return (float)a / b;
}

void fibonacci(int n) {
    int a = 0, b = 1, temp, i;

    printf("Secuencia de Fibonacci (%d terminos):\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}
