#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n1,n2,n3,n4;
    int menor, posicion;

    printf("Ingrese un número: ");
    scanf("%d", &n1);
    menor = n1;
    posicion = 1;

    printf("Ingrese un segundo número: ");
    scanf("%d", &n2);
    if (n2 < menor) {
        menor = n2;
        posicion = 2;
    }

    printf("Ingrese un tercer número: ");
    scanf("%d", &n3);
    if (n3 < menor) {
        menor = n3;
        posicion = 3;
    }

    printf("Ingrese un cuarto número: ");
    scanf("%d", &n4);
    if (n4 < menor) {
        menor = n4;
        posicion = 4;
    }

    printf("El menor es: %d. Posicion: %d", menor, posicion);

    return 0;
}
