/* Ingresar N y N Números naturales. Determinar e informar:
a. La sumatoria de los valores múltiplos de 3.
b. La cantidad de valores múltiplos de 5.
c. La sumatoria de los valores que se ingresan en orden par. */

#include <stdio.h>
#include <stdlib.h>

int main() { // o soy un low-wit y no entendí nada o este ejercicio está muy mal planteado, no se entiende bien lo que te está pidiendo hacer

    int N;
    int numeros;
    int suma3 = 0;
    int multiplos5 = 0;
    int posicionPar = 0;

    printf("Ingresar la cantidad de números naturales: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("El número ingresado no es un natural válido.\n");
        return 1;
    }

    for (int i = 1; i <= N; ++i) {
        printf("Ingresar el natural %d de %d: ", i, N); // creo, solo creo, que esto es lo que está pidiendo hacer, pero podría estar equivocado
        scanf("%d", &numeros);
    
    if (numeros % 3 == 0) {
        suma3 += numeros;
    }

    if (numeros % 5 == 0) {
        ++multiplos5;
    }

    if (i % 2 == 0) {
        posicionPar += numeros;
    }

    }
    
    printf("La sumatoria de los valores múltiplos de 3 es %d.\n", suma3);
    printf("Los valores múltiplos de 5 son %d.\n", multiplos5);
    printf("La sumatoria de valores en orden par es %d.\n", posicionPar);

    return 0;
}