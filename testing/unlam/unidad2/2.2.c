#include <stdio.h>
#include <stdlib.h>

float average(int eva1, int eva2)
{
    return (eva1 + eva2) / 2;
}

int main(void)
{
    int eva1, eva2;

    printf("Ingrese la nota de la primera evaluación: ");
    scanf("%d", &eva1);
    printf("Ingrese la nota de la segunda evaluacion: ");
    scanf("%d", &eva2);

    /* float promedio = average(eva1, eva2); */

    printf("El promedio es: %.2f", average(eva1, eva2));

    return 0;
}
