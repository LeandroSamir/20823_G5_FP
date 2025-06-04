#include <stdio.h>
int main() {
    int n, k, i;
    int vec[100];
    printf("Ingrese el numero de componentes para la sucesion(maximo 100): ");
    scanf("%i", &n);
    if (n<1 || n>100){
    	printf ("Numero de componentes invalidos.");
    	return 0;
	}
    for (k = 0; k < n; k++) {
        vec[k] = (k * k) + 3;
    }
    printf("Vector de la sucesion:\n");
    for (i = 0; i < n; i++) {
        printf("vec[%i] = %i\n", i, vec[i]);
    }
    return 0;
}
