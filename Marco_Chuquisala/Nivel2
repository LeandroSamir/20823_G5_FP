#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int min, max, intentosMax, intento, numeroSecreto;
    int intentos[10];  // Máximo de 10 intentos
    int contador = 0;
    int gano = 0;

    // RF01 - Configuración del rango
    printf("Define el rango:\n");
    printf("Minimo: ");
    scanf("%d", &min);
    printf("Maximo: ");
    scanf("%d", &max);

    if (min >= max) {
        printf("Rango invalido. El minimo debe ser menor que el máximo.\n");
        return 1;
    }

    // RF02 - Configuración del número de intentos (máximo 10)
    printf("¿Cuántos intentos deseas? (maximo 10): ");
    scanf("%d", &intentosMax);
    if (intentosMax < 1 || intentosMax > 10) {
        printf("Número de intentos inválido. Debe estar entre 1 y 10.\n");
        return 1;
    }

    // Generar número aleatorio dentro del rango
    srand(time(NULL));
    numeroSecreto = rand() % (max - min + 1) + min;

    // Juego principal
    for (int i = 0; i < intentosMax; i++) {
        printf("Intento %d - Adivina el numero (%d a %d): ", i + 1, min, max);
        scanf("%d", &intento);

        // RF03 - Validación del rango
        if (intento < min || intento > max) {
            printf("Numero fuera del rango. Intenta de nuevo.\n");
            i--;  // No cuenta como intento válido
            continue;
        }

        // RF04 - Registro del intento
        intentos[contador++] = intento;

        if (intento == numeroSecreto) {
            printf("Felicidades! Adivinaste el numero.\n");
            gano = 1;
            break;
        } else if (intento < numeroSecreto) {
            printf("Demasiado bajo.\n");
        } else {
            printf("Demasiado alto.\n");
        }
    }

    // RF05 - Visualización de resultados
    if (!gano) {
        printf("\nLo siento, no lograste adivinar el numero.\n");
    }

    printf("\nResumen del juego:\n");
    printf("Numero secreto: %d\n", numeroSecreto);
    printf("Intentos realizados:\n");
    for (int i = 0; i < contador; i++) {
        printf("Intento %d: %d\n", i + 1, intentos[i]);
    }

    return 0;
}
