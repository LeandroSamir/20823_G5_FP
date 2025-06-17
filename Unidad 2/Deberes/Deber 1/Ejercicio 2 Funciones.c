#include <stdio.h>

// Funciones
void llenarVector(int vec[], int tam);
int leerNumero(int numOrden);
int buscarNumero(int vec[], int tam, int num);
void mostrarResultado(int encontrado1, int encontrado2, int n1, int n2);

int main() {
    int vec[15];
    int n1, n2;
    int Bandera1, Bandera2;

    llenarVector(vec, 15);

    n1 = leerNumero(1);
    n2 = leerNumero(2);

    Bandera1 = buscarNumero(vec, 15, n1);
    Bandera2 = buscarNumero(vec, 15, n2);

    mostrarResultado(Bandera1, Bandera2, n1, n2);

    return 0;
}

// Funcion para llenar el vector del 1 al 15
void llenarVector(int vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        vec[i] = i + 1;
    }
}

// Funcion para leer un numero desde teclado
int leerNumero(int numOrden) {
    int num;
    printf("Valor numero %d a buscar: ", numOrden);
    scanf("%d", &num);
    return num;
}

// Funcion para buscar un numero en el vector
int buscarNumero(int vec[], int tam, int num) {
    for (int i = 0; i < tam; i++) {
        if (vec[i] == num) {
            return 1;
        }
    }
    return 0;
}

// Funcion para mostrar el resultado de la busqueda
void mostrarResultado(int encontrado1, int encontrado2, int n1, int n2) {
    if (encontrado1 && encontrado2) {
        printf("%d y %d pertenecen al vector\n", n1, n2);
    } else {
        printf("Uno o ambos numeros no pertenecen al vector\n");
    }
}
