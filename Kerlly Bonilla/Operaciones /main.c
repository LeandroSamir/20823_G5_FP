#include <stdio.h>
#include "mimath.h"  

int main() {
    int a = 10, b = 5;
    int n = 10;  

    printf("Suma: %d\n", suma(a, b));  
    printf("Resta: %d\n", resta(a, b));  
    printf("Multiplicación: %d\n", multiplicar(a, b)); 
    printf("División: %.2f\n", division((float)a, (float)b));  

    printf("Fibonacci de %d: %d\n", n, fibonacci(n));  
    return 0;
}
