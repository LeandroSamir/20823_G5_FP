#include <stdio.h>

#define SIZE 3

int main() {
    int cuadro[SIZE][SIZE];
    int fila, columna;
    int sumaFila, sumaColumna, diagonalP = 0, diagonals = 0;
    int esCuadradoMagico = 1;

    // 1) Se pide la matriz por teclado y se comprueba simultaneamente que los numeros estan entre 1 y 9.
    //    Si el valor no cumple, se vuelve a pedir.
    printf("Ingrese los elementos de la matriz 3x3 (valores entre 1 y 9):\n");
    for (fila = 0; fila < SIZE; fila++) {
        for (columna = 0; columna < SIZE; columna++) {
            do {
                printf("Elemento [%d][%d]: ", fila + 1, columna + 1);
                scanf("%d", &cuadro[fila][columna]);
                if (cuadro[fila][columna] < 1 || cuadro[fila][columna] > 9) {
                    printf("Error! Solo se permiten valores entre 1 y 9.\n");
                }
            } while (cuadro[fila][columna] < 1 || cuadro[fila][columna] > 9);
        }
    }

    // Mostrar la matriz
    printf("\nMatriz ingresada:\n");
    for (fila = 0; fila < SIZE; fila++) {
        for (columna = 0; columna < SIZE; columna++) {
            printf("%d ", cuadro[fila][columna]);
        }
        printf("\n");
    }

    // 2) Se calcula la suma por filas
    int sumaFila1 = 0;
    for (columna = 0; columna < SIZE; columna++) {
        sumaFila1 += cuadro[0][columna];
    }

    printf("\nSuma de filas:\n");
    for (fila = 0; fila < SIZE; fila++) {
        sumaFila = 0;
        for (columna = 0; columna < SIZE; columna++) {
            sumaFila += cuadro[fila][columna];
        }
        printf("Fila %d: %d\n", fila + 1, sumaFila);
        if (sumaFila != sumaFila1) esCuadradoMagico = 0;  // Si no coinciden, no es cuadrado magico
    }

    // 3) Si la suma por filas coincide, se calcula la suma por columnas
    printf("\nSuma de columnas:\n");
    if (esCuadradoMagico) {
        for (columna = 0; columna < SIZE; columna++) {
            sumaColumna = 0;
            for (fila = 0; fila < SIZE; fila++) {
                sumaColumna += cuadro[fila][columna];
            }
            printf("Columna %d: %d\n", columna + 1, sumaColumna);
            if (sumaColumna != sumaFila1) esCuadradoMagico = 0;
        }
    }

    // 4) Si la suma de columnas coincide, se calcula la suma de las diagonales
    if (esCuadradoMagico) {
        for (fila = 0; fila < SIZE; fila++) {
            diagonalP += cuadro[fila][fila];                // Diagonal principal
            diagonals += cuadro[fila][SIZE - 1 - fila];    // Diagonal secundaria
        }

        printf("\nSuma de diagonales:\n");
        printf("Diagonal principal: %d\n", diagonalP);
        printf("Diagonal secundaria: %d\n", diagonals);

        if (diagonalP != sumaFila1 || diagonals != sumaFila1) esCuadradoMagico = 0;
    }

    // 5) Si todas las sumas coinciden, se trata de un cuadrado magico y se imprime el resultado por pantalla
    if (esCuadradoMagico) {
        printf("\nEs un cuadrado magico.\n");
    } else {
        printf("\nNo es un cuadrado magico.\n");
    }

    return 0;
}

