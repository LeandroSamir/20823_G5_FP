#include <stdio.h>

int main() {
    int n;
    // Solicitar el tamaño de la matriz cuadrada
    printf("Ingrese el tamano de la matriz cuadrada (n x n): ");
    scanf("%d", &n);
    int matriz[n][n];
    int contador = 1;
    // Llenar la matriz en orden inverso
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            matriz[i][j] = contador++;
        }
    }
    // Impirimir la matriz
    printf("\nMatriz generada automáticamente (orden inverso):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
