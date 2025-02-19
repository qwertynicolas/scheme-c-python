#include <stdio.h>
#define AUTOS 60

void generarAboveAverage (float vA[], int autosParticipantes)
{
    int i, j = 0;
    float promedio = 0.0;

    for (i = 0; i < AUTOS; ++i) {
        if (vA[i] > 0) {
            promedio += vA[i];
        }
    }

    promedio /= autosParticipantes;

    for (i = 0; i < AUTOS; ++i) {
        if (vA[i] > promedio) {
            ++j;
        }
    }

    int aboveAverage [j];

    int k = 0;

    for (i = 0; i < AUTOS; ++i) {
        if (vA[i] > promedio) {
            aboveAverage[k] = i;
            ++k;
        }
    }

    printf("Autos con tiempo mayor que el promedio: ");

    for (i = 0; i < j; ++i) {
        printf("Nº%d ", aboveAverage[i]);
    }

    printf("\n");
}

void generarNoParticiparon (float vA[])
{
    int i;

    printf("Autos que no participaron: ");

    for (i = 0; i < AUTOS; ++i) {
        if (vA[i] == 0 && i != 0) {
            printf("Nº%d ", i);
        }
    }
}

int main (void)
{
    int vehiculo;
    float tiempo;
    int vehiculoPrimerLugar;
    float peorTiempo = 0.0;
    float tiempos [AUTOS];
    int vehiculoPeorTiempo;
    float mejorTiempo = 10000000000000000.0;

    int i;

    for (i = 0; i < AUTOS; ++i) {
        tiempos [i] = 0;
    }

    printf("Ingrese el número del vehiculo (1 - 60): ");
    scanf("%d", &vehiculo);

    while (vehiculo < 1 || vehiculo > 60) {
        printf("El número de auto no es válido. Intente nuevamente: ");
        scanf("%d", &vehiculo);
    }

    int cantidadAutos;

    cantidadAutos = 0;

    while (vehiculo > 0) {
        printf("Ingrese el tiempo del vehiculo Nº%d: ", vehiculo);
        scanf("%f", &tiempo);

        while (tiempo < 0.0) {
            printf("Tiempo no válido. Intente nuevamente: ");
            scanf("%f", &tiempo);
        }

        if (tiempo > peorTiempo) {
            peorTiempo = tiempo;
            vehiculoPeorTiempo = vehiculo;
        } else if (tiempo < mejorTiempo) {
            mejorTiempo = tiempo;
            vehiculoPrimerLugar = vehiculo;
        }

        ++cantidadAutos;

        tiempos [vehiculo] = tiempo;

        printf("Ingrese un nuevo auto o -1 para finalizar: ");
        scanf("%d", &vehiculo);

       while (vehiculo == 0 || vehiculo > 60) {
        printf("El número de auto no es válido. Intente nuevamente: ");
        scanf("%d", &vehiculo);
       }
    }

    printf("\n");
    printf("Primer puesto: Auto Nº%d. Tiempo: %.2f\n", vehiculoPrimerLugar, mejorTiempo);
    printf("Último puesto: Auto Nº%d. Tiempo: %.2f\n", vehiculoPeorTiempo, peorTiempo);

    printf("\n");

    generarAboveAverage(tiempos, cantidadAutos);
    generarNoParticiparon(tiempos);

    return 0;
}
