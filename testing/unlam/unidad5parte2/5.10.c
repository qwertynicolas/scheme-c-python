#include <stdio.h>

int main (void)
{
    int posicion, posMax, posMin;
    float temp, tempMax, tempMin;
    int continuar = 1;

    posicion = posMax = posMin = 1;
    tempMax = 0.0;
    tempMin = 10000000000.00;

    while (continuar) {
        printf("Ingrese el valor de temperatura: ");
        scanf("%f", &temp);

        if (temp == -50) {
            continuar = 0;
        } else {
            if (temp > tempMax) {
                tempMax = temp;
                posMax = posicion;
            }

            if (temp < tempMin) {
                tempMin = temp;
                posMin = posicion;
            }
        }

        ++posicion;
    }

    printf("Valor máximo: %.2f Posicion: %d\n", tempMax, posMax);
    printf("Valor mínimo: %.2f Posicion: %d\n", tempMin, posMin);

    return 0;
}
