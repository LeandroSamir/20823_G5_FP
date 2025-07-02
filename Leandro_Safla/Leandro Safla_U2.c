#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    int minimo, maximo, intentos, secreto;
    int historial[MAX_INTENTOS][3];
    int intento_actual = 0;
    int valor, repetido, adivinado = 0;

    // RF1: Configuración dinámica del rango
    printf("Ingrese el rango minimo: ");
    scanf("%d", &minimo);
    printf("Ingrese el rango maximo: ");
    scanf("%d", &maximo);

    if (minimo >= maximo) {
        printf("Rango invalido. El minimo debe ser menor que el maximo.\n");
        return 1;
    }

    // RF2: Selección del número de intentos
    do {
        printf("Ingrese la cantidad de intentos (1 a 10): ");
        scanf("%d", &intentos);
    } while (intentos < 1 || intentos > MAX_INTENTOS);

    // Generar número secreto
    srand(time(NULL));
    secreto = rand() % (maximo - minimo + 1) + minimo;

    // RF3, RF4: Validar e ingresar intentos válidos
    while (intento_actual < intentos) {
        repetido = 0;
        printf("\nIntento %d de %d - Ingrese un numero entre %d y %d: ",
               intento_actual + 1, intentos, minimo, maximo);
        scanf("%d", &valor);

        if (valor < minimo || valor > maximo) {
            printf(" Nmero fuera de rango. No se cuenta como intento.\n");
            continue;
        }

        for (int i = 0; i < intento_actual; i++) {
            if (historial[i][1] == valor) {
                repetido = 1;
                break;
            }
        }

        if (repetido) {
            printf("  Numero repetido. No se cuenta como intento.\n");
            continue;
        }

        historial[intento_actual][0] = intento_actual + 1;
        historial[intento_actual][1] = valor;

        if (valor < secreto) {
            historial[intento_actual][2] = 0;
        } else if (valor > secreto) {
            historial[intento_actual][2] = 1;
        } else {
            historial[intento_actual][2] = 2;
            adivinado = 1;
        }

        intento_actual++;

        if (adivinado) {
            printf("\n Felicidades Adivinaste el numero secreto.\n");
            break;
        }
    }

    // RF5: Mostrar resumen
    printf("\nResumen de intentos:\n");
    printf("+---------+----------------+----------------+\n");
    printf("| Intento | Valor ingresado | Resultado     |\n");
    printf("+---------+----------------+----------------+\n");

    for (int i = 0; i < intento_actual; i++) {
        printf("|   %2d    |      %5d      | ",
               historial[i][0], historial[i][1]);
        switch (historial[i][2]) {
            case 0: printf("Muy bajo     |\n"); break;
            case 1: printf("Muy alto     |\n"); break;
            case 2: printf("Correcto     |\n"); break;
        }
    }


    if (!adivinado) {
        printf("\n No adivinaste el numero secreto. Era: %d\n", secreto);
    }

    return 0;
}
