#include <stdio.h>
int main() {
    int N;

    // RF1: El programa debe permitir ingresar el tamaño N de la matriz
    printf("Ingrese el tamano N de la matriz (NxN): ");
    scanf("%d", &N);

    // RF2: El programa debe permitir validar que el tamaño sea un entero positivo
    if (N <= 0) {
        printf("El tamano debe ser un numero entero positivo.\n");
        return 1;
    }

    int matriz[N][N];

    // RF3: El programa debe permitir ingresar los elementos de la matriz
    printf("Ingrese los valores enteros de la matriz (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int fila;

    // RF4: El programa debe permitir ingresar el número de una fila
    printf("Ingrese el numero de la fila a analizar (0 a %d): ", N - 1);
    scanf("%d", &fila);

    // RF5: El programa debe permitir validar que la fila esté en el rango valido
    if (fila < 0 || fila >= N) {
        printf("Numero de fila invalido.\n");
        return 1;
    }

    // RF6: El programa debe permitir calcular el valor maximo de la fila
    int max = matriz[fila][0];
    for (int j = 1; j < N; j++) {
        if (matriz[fila][j] > max) {
            max = matriz[fila][j];
        }
    }

    // RF7: El programa debe permitir mostrar el resultado
    printf("El valor maximo en la fila %d es: %d\n", fila, max);

    return 0;
}
