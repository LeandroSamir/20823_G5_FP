#include <stdio.h>

int main() {
    int vec[10];
    float norma = 0.0;
    int i;


    printf("Ingrese el numero hasta 10 componentes :\n");
    for (i = 0; i < 10; i++) {
        printf("Componente %d: ", i + 1);
        scanf("%f", &vec[i]);
    }


    for (i = 0; i < 10; i++) {
        norma = norma + (vec[i] * vec[i]);
    }


    printf("La norma del vector (suma de cuadrados) es: %.2f\n", norma);

    return 0;
}
