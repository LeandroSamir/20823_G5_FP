#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    int minimo, maximo, intentos, secreto;
    int historial[MAX_INTENTOS][3];
    int intento_actual = 0;
    int valor, repetido, adivinado = 0;


    printf("Ingrese el rango minimo: ");
    scanf("%d", &minimo);
    printf("Ingrese el rango maximo: ");
    scanf("%d", &maximo);

    if (minimo >= maximo) {
        printf("Rango inválido. El mínimo debe ser menor que el máximo.\n");
        return 1;
do {
        printf("Ingrese la cantidad de intentos (1 a 10): ");
        scanf("%d", &intentos);
    } while (intentos < 1 || intentos > MAX_INTENTOS);


    srand(time(NULL));
    secreto = rand() % (maximo - minimo + 1) + minimo;


    while (intento_actual < intentos) {
        repetido = 0;
        printf("\nIntento %d - Ingrese un número entre %d y %d: ", intento_actual + 1, minimo, maximo);
        scanf("%d", &valor);

         if (valor < minimo || valor > maximo) {
            printf("Número fuera de rango.\n");
            continue;
        }






