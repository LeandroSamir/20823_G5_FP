#include <stdio.h>
#define TAM 15

void inicializarVector(int vec[], int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }
}

void calcularFactoriales(int vec[], unsigned long long int fac[], int n) {
    for (int i = 0; i < n; i++) {
        fac[i] = 1;
        for (int j = 1; j <= vec[i]; j++) {
            fac[i] *= j;
        }
    }
}

void mostrarFactoriales(int vec[], unsigned long long int fac[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%2d! = %llu\n", vec[i], fac[i]);
    }
}

int main() {
    int vec[TAM];
    unsigned long long int fac[TAM];

    inicializarVector(vec, TAM);
    calcularFactoriales(vec, fac, TAM);
    mostrarFactoriales(vec, fac, TAM);

    return 0;
}
