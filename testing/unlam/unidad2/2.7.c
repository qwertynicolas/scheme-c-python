#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int numero;

    printf("Ingrese un número de 3 cifras: ");
    scanf("%d", &numero);

    int centenas = numero / 100;

    numero -= (100 * centenas);

    int decenas = numero / 10;

    numero -= (10 * decenas);

    printf("Centenas: %d\n", centenas);
    printf("Decenas: %d\n", decenas);
    printf("Unidades: %d\n", numero);

    return 0;
}
