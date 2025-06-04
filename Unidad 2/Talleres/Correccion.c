#include <stdio.h>
int main() {
    int vector[10];
    int cantidad, i, norma;
    norma = 0;
    printf("Ingrese la cantidad de componentes (1 a 10): ");
    scanf("%i", &cantidad);
    if (cantidad < 1 || cantidad > 10) {
        printf("Cantidad de componentes invalida\n");
        return 0;
    }
    printf("Ingrese los componentes:\n");
    for (i = 0; i < cantidad; i++) {
        printf("Componente %i: ", i + 1);
        scanf("%i", &vector[i]);
        norma = norma + vector[i] * vector[i];
    }
    printf("La norma de los componentes es: %i", norma);
    return 0;
}
