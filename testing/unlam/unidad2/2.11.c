#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int docenas, unidades;

    printf("Ingrese la cantidad de empanadas que desea comprar: ");
    scanf("%d", &unidades);

    docenas = unidades / 12;
    unidades = unidades % 12;

    float costoTotal = (docenas * 300) + (unidades * 30);

    printf("El costo total es %.2f.\n", costoTotal);

    return 0;
}
