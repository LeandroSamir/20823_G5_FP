#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    int min, max, numero_secreto;
    int intentos_max, intento = 0;
    int registros[MAX_INTENTOS][3]; 
    int adivinado = 0;
    int valor;

    // RF1: Configuración dinámica de rango
    printf("Ingrese el rango mínimo del número secreto: ");
    scanf("%d", &min);
    printf("Ingrese el rango máximo del número secreto: ");
    scanf("%d", &max);

    if (min >= max) {
        printf("Rango inválido. El mínimo debe ser menor que el máximo.\n");
        return 1;
    }

    // RF2: Configuración dinámica de intentos
    do {
        printf("Ingrese el número máximo de intentos (1 a 10): ");
        scanf("%d", &intentos_max);
    } while (intentos_max < 1 || intentos_max > MAX_INTENTOS);

    srand(time(NULL));
    numero_secreto = rand() % (max - min + 1) + min;

    int valores_ingresados[MAX_INTENTOS] = {0};

    while (intento < intentos_max && !adivinado) {
        printf("Intento %d - Ingrese un número entre %d y %d: ", intento + 1, min, max);
        scanf("%d", &valor);

        // RF3: Validación de rango y duplicados
        if (valor < min || valor > max) {
            printf("Número fuera de rango.\n");
            continue;  
        }
        int duplicado = 0;
        for (int i = 0; i < intento; i++) {
            if (valores_ingresados[i] == valor) {
                duplicado = 1;
                break;
            }
        }
        if (duplicado) {
            printf("Ya ingresaste ese número. Intenta con otro.\n");
            continue;  
        }
        valores_ingresados[intento] = valor;
        registros[intento][0] = intento + 1;  
        registros[intento][1] = valor;        
        registros[intento][2] = (valor < numero_secreto) ? 0 : (valor > numero_secreto) ? 1 : 2; 

        if (valor == numero_secreto) {
            adivinado = 1;
        }

        intento++; 

        // RF5: Visualización de resumen
        printf("\nResumen de intentos:\n");
        printf("Intento\tValor\tResultado\n");
        for (int i = 0; i < intento; i++) {
            printf("%d\t%d\t", registros[i][0], registros[i][1]);
            switch (registros[i][2]) {
                case 0: printf("Muy bajo\n"); break;
                case 1: printf("Muy alto\n"); break;
                case 2: printf("Correcto\n"); break;
            }
        }
        printf("\n");
    }

    if (adivinado) {
        printf("¡Felicidades! Adivinaste el número secreto %d en %d intentos.\n", numero_secreto, intento);
    } else {
        printf("No adivinaste el número. Era: %d\n", numero_secreto);
    }

    return 0;
}
