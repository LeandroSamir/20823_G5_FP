#include <stdio.h>

int main() {
    int n;

    // Solicitar el tamaño de la matriz cuadrada
    printf("Introduce el tamaño de la matriz (n x n): ");
    scanf("%d", &n);

    int matriz[n][n];

    // Ingreso de los elementos de la matriz
    printf("Introduce los elementos de la matriz (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Mostrar la matriz original
    printf("\nMatriz original:\n");
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%4d", matriz[r][c]);
        }
        printf("\n");
    }

    int i, j;
    // Solicitar las filas a intercambiar
    printf("\nIntroduce los números de las dos filas a intercambiar (0 a %d): ", n - 1);
    scanf("%d %d", &i, &j);

    // Validar índices
    if (i < 0 || i >= n || j < 0 || j >= n) {
        printf("Índices fuera de rango. Terminando el programa.\n");
        return 1;
    }

    // Intercambiar las filas i y j
    for (int k = 0; k < n; k++) {
        int aux = matriz[i][k];
        matriz[i][k] = matriz[j][k];
        matriz[j][k] = aux;
    }

    // Mostrar la matriz después del intercambio
    printf("\nMatriz después de intercambiar las filas %d y %d:\n", i, j);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%4d", matriz[r][c]);
        }
        printf("\n");
    }

    return 0;
}
