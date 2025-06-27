#include <stdio.h>
#include "math.h"


int main() {
    float a = 8.0, b = 2.0;
    int m = 7;

    printf("Operaciones basicas con %.2f y %.2f:\n", a, b);
    printf("Suma: %.2f\n", sumar(a, b));
    printf("Resta: %.2f\n", restar(a, b));
    printf("Multiplicacion: %.2f\n", multiplicar(a, b));
    printf("Division: %.2f\n", dividir(a, b));

    fibonacci(m);

    return 0;
}
