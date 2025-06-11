#include <stdio.h>
int main() {
    int F, C, i, j, FE, VM;
    
    //RF1: Ingresar numero de filas y columnas
    printf("Ingrese el numero de filas: ");
    scanf("%i", &F);
    printf("Ingrese el numero de columnas: ");
    scanf("%i", &C);

    int matriz[F][C];
    
    //RF2: Ingresar los elementos de la matriz
    printf("Ingrese los elementos de la matriz:\n");
    for (i = 0; i < F; i++) {
        for (j = 0; j < C; j++) {
            printf("Elemento [%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
    
    //RF3: Solicitar al usuario que elija una fila
    printf("Eliga una fila (0 a %d): ", F-1);
    scanf("%i", &FE);

    if (FE < 0 || FE >= F) {
        printf("La fila ingresada no es valida para esta matriz.\n");
        return 1;
    }

    VM = matriz[FE][0];
    for (int j = 1; j < C; j++) {
        if (matriz[FE][j] > VM) {
            VM = matriz[FE][j];
        }
    }

    //RF4: Imprimir el valor maximo
    printf("El valor maximo en la fila %i es: %i",FE, VM);
    return 0;
}
