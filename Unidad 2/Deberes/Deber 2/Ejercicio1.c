#include <stdio.h>

int main() {
    int n;

    // Solicitar el tamano de la matriz cuadrada
    printf("Ingrese el tamano de la matriz cuadrada (n x n): ");
    scanf("%d", &n);

    int matriz[n][n];

    printf("Ingrese los elementos de la matriz desde la ultima fila y columna hasta la primera:\n");

    // Entrada de la matriz en orden inverso (de abajo hacia arriba y de derecha a izquierda)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Mostrar la matriz
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
