#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
    int tarros;

    printf("Ingrese la cantidad de tarros totales: ");
    scanf("%d", &tarros);

    int unLitro = (int) ceil(tarros * 0.5);
    int cuatroLitros = (int) ceil(tarros * 0.3);
    int veinteLitros = (int) ceil(tarros * 0.2);

    printf("Hay %d tarros de 1 litro.\n", unLitro);
    printf("Hay %d tarros de 4 litros.\n", cuatroLitros);
    printf("Hay %d tarros de 20 litros.\n", veinteLitros);

    return 0;
}
