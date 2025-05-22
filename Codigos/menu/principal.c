#include <stdio.h>
#include "ejercicios.h"
#include <math.h>

void menu1_10() {
    int opcion;
        printf("\nMENU DE EJERCICIOS 1-10\n");
        for (int i = 1; i <= 10; i++)
            printf("%d. Ejercicio %d\n", i, i);
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: ejercicio7(); break;
            case 8: ejercicio8(); break;
            case 9: ejercicio9(); break;
            case 10: ejercicio10(); break;
            default: printf("Opcion no valida.\n");
    }
}

void menu11_20() {
    int opcion;
        printf("\nMENU DE EJERCICIOS 11-20\n");
        for (int i = 1; i <= 10; i++)
            printf("%d. Ejercicio %d\n", i, i + 10);
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: ejercicio11(); break;
            case 2: ejercicio12(); break;
            case 3: ejercicio13(); break;
            case 4: ejercicio14(); break;
            case 5: ejercicio15(); break;
            case 6: ejercicio16(); break;
            case 7: ejercicio17(); break;
            case 8: ejercicio18(); break;
            case 9: ejercicio19(); break;
            case 10: ejercicio20(); break;
            default: printf("Opcion no valida.\n");
        }
}

int main() {
    int opcion;
        printf("MENU PRINCIPAL\n");
        printf("1. Ejercicios 1 al 10\n");
        printf("2. Ejercicios 11 al 20\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: menu1_10(); break;
            case 2: menu11_20(); break;
            default: printf("Opcion no valida.\n");
    }

    return 0;
}
