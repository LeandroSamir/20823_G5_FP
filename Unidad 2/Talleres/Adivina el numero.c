#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 5

void ingresarDatos(int intentos[], int *adivinado, int numeroSecreto, int *intentosRealizados);
void imprimirIntentos(int intentos[], int intentosRealizados);

int main() {
    int numeroSecreto, adivinado = 0;
    int intentos[MAX_INTENTOS];
    int intentosRealizados = 0;

    srand(time(NULL));
    numeroSecreto = rand() % 100 + 1;

    printf("Adivina el numero entre 1 y 100. Tienes %d intentos.\n", MAX_INTENTOS);

    ingresarDatos(intentos, &adivinado, numeroSecreto, &intentosRealizados);

    if (adivinado) {
        printf("¡Correcto! Adivinaste el numero durante los intentos.\n");
    } else {
        printf("No lograste adivinar. El numero era: %d\n", numeroSecreto);
    }

    imprimirIntentos(intentos, intentosRealizados);

    return 0;
}

void ingresarDatos(int intentos[], int *adivinado, int numeroSecreto, int *intentosRealizados) {
    int intento;
    for (int i = 0; i < MAX_INTENTOS; i++) {
        printf("Intento %d: ", i + 1);
        scanf("%d", &intento);
        intentos[i] = intento;
        *intentosRealizados = i + 1;

        if (intento == numeroSecreto) {
            *adivinado = 1;
            printf("¡Correcto!\n");
            break;
        } else if (intento < numeroSecreto) {
            printf("El numero es más alto.\n");
        } else {
            printf("El numero es más bajo.\n");
        }
    }
}

void imprimirIntentos(int intentos[], int intentosRealizados) {
    printf("Tus intentos fueron: ");
    for (int i = 0; i < intentosRealizados; i++) {
        printf("%d ", intentos[i]);
    }
    printf("\n");
}
