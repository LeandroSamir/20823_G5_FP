// main.c
#include <stdio.h>
#include "operaciones.h"

int main() {
    float x = 5.0, y = 3.0;
    int n = 10;

    printf("Operaciones basicas con %.2f y %.2f:\n", x, y);
    printf("Suma: %.2f\n", sumar(x, y));
    printf("Resta: %.2f\n", restar(x, y));
    printf("Multiplicacion: %.2f\n", multiplicar(x, y));
    printf("Division: %.2f\n", dividir(x, y));

    // Fibonacci
    fibonacci(n);

    return 0;
}
