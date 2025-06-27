#include <stdio.h>
#include "mimath.h"  

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) {
        printf("Error: División por cero.\n");
        return 0;
    }
    return a / b;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
