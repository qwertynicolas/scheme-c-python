#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int clase_turista = 8800;
    int primera_clase = clase_turista * 1.30;
    int boletosTurista, boletosPrimera;

    printf("Ingrese la cantidad de boletos vendidos de clase turista: ");
    scanf("%d", &boletosTurista);
    printf("Ingrese la cantidad de boletos vendidos de primera clase: ");
    scanf("%d", &boletosPrimera);

    int total = (clase_turista * boletosTurista) + (primera_clase * boletosPrimera);

    printf("Total recaudado: %d", total);

    return 0;
}
