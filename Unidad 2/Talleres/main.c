#include <stdio.h>
#include <stdlib.h>
int main() {
    int matriz[10][10];
    int suma = 0;
    int i, j;
    int adivinanza;
    printf("INRGRESE UNA MATRIZ DE 10X10\n");

    for (i = 0; i < 10; i++) {
        printf("Ingrese los valores de la fila %d:\n", i);
        for (j = 0; j < 10; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            suma = suma + matriz[i][j];
        }
        #ifdef _WIN32
           system("cls");
        #endif
    }
    printf("\nAdivine la suma total de los elementos de la matriz: ");
    scanf("%d", &adivinanza);

    if (adivinanza == suma) {
        printf("CORRECTO\nLa suma total es %d.\n", suma);
    } else {
        printf("Incorrecto. La suma total era %d.\n", suma);
    }
    return 0;
}
