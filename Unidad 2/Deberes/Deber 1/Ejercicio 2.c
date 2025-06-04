#include <stdio.h>

int main() {
    int vec[15];
    int Bandera1 = 0, Bandera2 = 0;
    int n1, n2;

    
    for (int i = 0; i < 15; i++) {
        vec[i] = i + 1; // Llenar el vector con valores del 1 al 15
    }

    printf("Valor número 1 a buscar: ");
    scanf("%d", &n1);
    printf("Valor número 2 a buscar: ");
    scanf("%d", &n2);

  
    for (int i = 0; i < 15; i++) {
        if (n1 == vec[i]) {
            Bandera1 = 1;
        }
        if (n2 == vec[i]) {
            Bandera2 = 1;
        }
    }

    if (Bandera1 == 1 && Bandera2 == 1) {
        printf("%d y %d pertenecen al vector\n", n1, n2);
    } else {
        printf("Uno o ambos números no pertenecen al vector\n");
    }

    return 0;
}
