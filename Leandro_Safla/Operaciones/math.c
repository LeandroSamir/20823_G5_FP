#include <stdio.h>
#include "math.h"

float sumar(float x, float y) {
    return x + y;
}

float restar(float x, float y) {
    return x - y;
}

float multiplicar(float x, float y) {
    return x * y;
}

float dividir(float x, float y) {
    if (y == 0) {
        printf("Error: Division por cero.\n");
        return 0;
    }
    return x / y;
}

void fibonacci(int t) {
    int f1 = 0, f2 = 1, fn, j;

    printf("Secuencia de Fibonacci (%d terminos):\n", t);
    for (j = 0; j < t; j++) {
        printf("%d ", f1);
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    printf("\n");
}
