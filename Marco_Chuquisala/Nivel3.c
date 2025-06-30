#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int yaFueIngresado(int matriz[][3], int intentosRealizados, int valor) {
    for (int i = 0; i < intentosRealizados; i++) {
        if (matriz[i][1] == valor) {
            return 1;  // Ya se intentó ese valor
        }
    }
    return 0;
}

int main() {
    int min, max, intentosMax, intento;
    int matriz[MAX_INTENTOS][3];  // [número de intento, valor ingresado, resultado]
    int numeroSecreto;
    int contador = 0;
    int gano = 0;

    // RF01 - Rango dinámico
    printf("Defina el rango del numero secreto:\n");
    printf("Minimo: ");
    scanf("%d", &min);
    printf("Maximo: ");
    scanf("%d", &max);

    if (min >= max) {
        printf("Rango invalido.\n");
        return 1;
    }

    // RF02 - Número de intentos
    printf("Numero maximo de intentos (hasta 10): ");
    scanf("%d", &intentosMax);
    if (intentosMax < 1 || intentosMax > MAX_INTENTOS) {
        printf("Numero de intentos invalido.\n");
        return 1;
    }

    // Generar número aleatorio
    srand(time(NULL));
    numeroSecreto = rand() % (max - min + 1) + min;

    // Juego principal
    while (contador < intentosMax) {
        printf("\nIntento %d - Ingrese un numero entre %d y %d: ", contador + 1, min, max);
        scanf("%d", &intento);

        // RF03 - Validación de rango
        if (intento < min || intento > max) {
            printf("Fuera del rango. Intente nuevamente.\n");
            continue;
        }

        // RF03 - Validación de duplicados
        if (yaFueIngresado(matriz, contador, intento)) {
            printf("Ya intentaste ese numero. Intenta uno diferente.\n");
            continue;
        }

        // Guardar datos en la matriz
        matriz[contador][0] = contador + 1;  // Número de intento
        matriz[contador][1] = intento;       // Valor ingresado

        // Comparar con número secreto
        if (intento == numeroSecreto) {
            matriz[contador][2] = 2; // Correcto
            gano = 1;
            break;
        } else if (intento < numeroSecreto) {
            matriz[contador][2] = 0; // Bajo
            printf("Demasiado bajo.\n");
        } else {
            matriz[contador][2] = 1; // Alto
            printf("Demasiado alto.\n");
        }

        contador++;
    }

    // RF05 - Mostrar resumen
    printf("\n=== RESUMEN DEL JUEGO ===\n");
    printf("Intento | Valor ingresado | Resultado\n");
 
   printf("-------------------------------------\n");
    for (int i = 0; i <= contador; i++) {
        printf("   %2d   |      %3d       |  ", matriz[i][0], matriz[i][1]);
        switch (matriz[i][2]) {
            case 0:
                printf("Bajo\n");
                break;
            case 1:
                printf("Alto\n");
                break;
            case 2:
                printf("Correcto\n");
                break;
        }
    }

    if (!gano) {
        printf("\nNo adivinaste el numero. El numero secreto era: %d\n", numeroSecreto);
    } else {
        printf("\nFelicidades! Adivinaste el numero secreto: %d\n", numeroSecreto);
    }

    return 0;
}
