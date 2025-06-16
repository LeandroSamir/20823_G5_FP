#include <stdio.h>

int main() {
    int n;

    // RF1: Solicitar el tamaño de la matriz cuadrada
    printf("Introduce el tamano de la matriz (n x n): ");
    scanf("%d", &n);

    int matriz[n][n];

    // RF2: Llenar la matriz
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valor++;
        }
    }

    // RF3: Mostrar la matriz original
    printf("\nMatriz original:\n");
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%4d", matriz[r][c]);
        }
        printf("\n");
    }

    int i, j;
    // RF4: Solicitar las filas a intercambiar
    printf("\nIntroduce los numeros de las dos filas a intercambiar (0 a %d): ", n - 1);
    scanf("%d %d", &i, &j);

    // Validar índices
    if (i < 0 || i >= n || j < 0 || j >= n) {
        printf("Fuera de rango.\n");
        return 1;
    }

    // RF5: Intercambiar las filas i y j
    for (int k = 0; k < n; k++) {
        int aux = matriz[i][k];
        matriz[i][k] = matriz[j][k];
        matriz[j][k] = aux;
    }

    // RF6: Mostrar la matriz despues del intercambio
    printf("\nMatriz despues de intercambiar las filas %d y %d:\n", i, j);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%4d", matriz[r][c]);
        }
        printf("\n");
    }

    return 0;
}
