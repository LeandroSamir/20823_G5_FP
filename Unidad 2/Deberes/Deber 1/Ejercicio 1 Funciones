#include <stdio.h>

// Funciones
int leerCantidad();
void generarSucesion(int vec[], int n);
void mostrarSucesion(int vec[], int n);

int main() {
    int n;
    int vec[100];

    n = leerCantidad();
    if (n < 1 || n > 100) {
        printf("Numero de componentes invalido.\n");
        return 0;
    }

    generarSucesion(vec, n);
    mostrarSucesion(vec, n);

    return 0;
}

// Funcion para leer la cantidad de elementos
int leerCantidad() {
    int cantidad;
    printf("Ingrese el numero de componentes para la sucesion k*k+3 (entre 0 y 100): ");
    scanf("%i", &cantidad);
    return cantidad;
}

// Funcion para llenar el vector con la sucesión (k^2 + 3)
void generarSucesion(int vec[], int n) {
    for (int k = 0; k < n; k++) {
        vec[k] = (k * k) + 3;
    }
}

// Funcion para mostrar el vector
void mostrarSucesion(int vec[], int n) {
    printf("Vector de la sucesion:\n");
    for (int i = 0; i < n; i++) {
        printf("vec[%i] = %i\n", i, vec[i]);
    }
}
