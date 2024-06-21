/*Confeccionar un programa para calcular la suma de los primeros N números naturales. El valor de N lo
solicita por teclado el programa */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int suma = 0;
    int natural;

    printf("Ingrese un número natural: ");
    scanf("%d", &natural);

    if (natural <= 0) { // no se toma en cuenta a 0 en el conjunto de los naturales en este caso
        printf("El número ingresado no es un natural.\n");
        return 1;
    }
    
    for (int i = 1; i <= natural; ++i) {
        suma += i;
    }   

    printf("La suma de los primeros %d números naturales es %d.\n", natural, suma); 

    return 0;
}
