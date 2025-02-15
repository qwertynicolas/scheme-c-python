#include <stdio.h>
#include <stdlib.h>

#define PI 3.14169265359

float radian_grado (float degrees)
{
    return degrees * (PI / 180);
}

float grado_radian (float radians)
{
    return (radians * PI) * (180 / PI);
}

int main (void)
{
    int codigo;
    float valor;
    float cambio;

    printf("1 para grados - 2 para radianes: ");
    scanf("%d", &codigo);

    if (codigo != 1 && codigo != 2) {
        printf("El código es NO válido.\n");
        return main();
    }

    printf("Ingrese el valor: ");
    scanf("%f", &valor);

    if (codigo == 1) {
        cambio = radian_grado(valor);
        printf("Valor en radianes: %.2f", cambio);
    } else {
        cambio = grado_radian(valor);
        printf("Valor en grados: %.2f", cambio);
    }

    return 0;
}
