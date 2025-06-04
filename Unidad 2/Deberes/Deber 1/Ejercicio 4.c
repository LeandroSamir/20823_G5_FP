#include <stdio.h>
#define TAM 10

void inicializar(int v[]);
void ordenar(int v[], int tam);
void mostrar(int v[], int tam);

int main() {
    int vec[TAM];

    inicializar(vec);
    ordenar(vec, TAM);
    mostrar(vec, TAM);

    return 0;
}
void inicializar(int v[]) {
    int datos[TAM] = {45, 12, 78, 23, 56, 89, 34, 67, 10, 90};
    for (int i = 0; i < TAM; i++) {
        v[i] = datos[i];
    }
}
void ordenar(int v[], int tam) {
    int aux;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (v[i] < v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
void mostrar(int v[], int tam) {
    printf("Vector ordenado de mayor a menor:\n");
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: %d\n", i, v[i]);
    }
}
