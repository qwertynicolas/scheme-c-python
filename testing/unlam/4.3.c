/* Confeccionar un programa que pueda determinar de 3 números enteros que se ingresan si alguno de ellos
es igual a la suma de los otros dos. */


#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1, n2, n3; 

    printf("Ingrese el primer número: ");
    scanf("%d", &n1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &n2);   
    printf("Ingrese el tercer número: ");
    scanf("%d", &n3);

    if (n1 == n2 + n3) { // tal vez haya una forma mas óptima de hacer esto?
        printf("El primer número es igual a la suma de los otros dos.\n");
    }   else if (n2 == n1 + n3) {
        printf("El segundo número es igual a la suma de los otros dos.\n");
    }   else if (n3 == n1 + n2) {
        printf("El tercer número es igual a la suma de los otros dos.\n");
    } else {
        printf("Ningun número es igual a la suma de los otros dos.\n");
    }

    return 0;
}