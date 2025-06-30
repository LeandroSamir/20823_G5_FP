#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    int min, max;
    int numeroSecreto;
    int intentosMax;
    int intentos[MAX_INTENTOS][3];
    int intentosRealizados = 0;
    int adivinado = 0;

    srand(time(NULL)); //Generador de numeros aleatorios

    // RF1. Validar rango (minimo y maximo)
    printf("Ingrese el rango (valor ninimo): ");
    scanf("%d", &min);
    printf("Ingrese el rango (valor maximo): ");
    scanf("%d", &max);
    while (max <= min) {
        printf("Error: el maximo debe ser mayor que el minimo. Ingrese nuevamente.\n");
        printf("Minimo: ");
        scanf("%d", &min);
        printf("Maximo: ");
        scanf("%d", &max);
    }
    numeroSecreto = min + rand() % (max - min + 1); // Generar numero secreto aleatorio

    // RF2. Configuracion de la cantidad de intentos
    do {
        printf("Ingrese la cantidad de intentos que desea (maximo 10): ");
        scanf("%d", &intentosMax);
    } while (intentosMax < 1 || intentosMax > MAX_INTENTOS);

    while (intentosRealizados < intentosMax) {
        int valor, repetido = 0;
        printf("\nIntento %d: Ingrese un numero entre %d y %d: ", intentosRealizados + 1, min, max);
        scanf("%d", &valor);

        // RF3. Validar rango y duplicados
        if (valor < min || valor > max) {
            printf("Numero fuera del rango. Intente nuevamente.\n");
            continue;
        }
        for (int i = 0; i < intentosRealizados; i++) {
            if (intentos[i][1] == valor) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            printf("Ya ingresaste ese numero antes. Intenta con uno diferente.\n");
            continue;
        }

        // RF4. Almacenar en una matriz, intentos valor y resultado
        intentos[intentosRealizados][0] = intentosRealizados + 1;
        intentos[intentosRealizados][1] = valor;

        if (valor < numeroSecreto) {
            intentos[intentosRealizados][2] = 0; // Bajo
            printf("Fallaste! El numero secreto es MAS ALTO.\n");
        } else if (valor > numeroSecreto) {
            intentos[intentosRealizados][2] = 1; // Alto
            printf("Fallaste! el numero secreto es MAS BAJO.\n");
        } else {
            intentos[intentosRealizados][2] = 2; // Correcto
            adivinado = 1;
            printf("MUY BIEN! Adivinaste el numero secreto.\n");
            break;
        }
        intentosRealizados++;
    }

    // RF5. Mostrar tabla de intentos y revelar el numero secreto si no se adivino
    printf("\n    TABLA DE RESULTADOS\n");
    printf("Intento\tValor\tResultado\n");
    for (int i = 0; i < intentosRealizados + adivinado; i++) {
        printf("%d\t%d\t", intentos[i][0], intentos[i][1]);
        switch (intentos[i][2]) {
            case 0: printf("Bajo"); break;
            case 1: printf("Alto"); break;
            case 2: printf("Correcto"); break;
        }
        printf("\n");
    }
    if (!adivinado) {
        printf("\nLastima :( no lograste adivinar el numero secreto. Era: %d\n", numeroSecreto);
    }
    return 0;
}
