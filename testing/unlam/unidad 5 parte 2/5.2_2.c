/* Escribir las sentencias que permitan el ingreso correcto del valor numérico de un día y un mes
determinado. Por algún error volver a solicitar. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int dia, mes;

    while (1) {
        printf("Ingrese el día: ");
        scanf("%d", &dia);
        printf("Ingrese el mes: ");
        scanf("%d", &mes);

        if (mes > 12 || mes < 1) {
            printf("No es un valor válido, vuelva a ingresar los valores.\n");
            continue;
        }

        if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) {
            printf("No es un valor válido, vuelva a ingresar los valores.\n");
            continue;
        }

        if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)) {
            printf("No es un valor válido, vuelva a ingresar los valores.\n");
            continue;
        }

        if (mes == 2 && (dia < 1 || dia > 29)) {
            printf("Día no válido para Febrero, vuelva a ingresar los valores.\n");
            continue;
        }

        printf("Día y mes: %02d/%02d\n", dia, mes);
        break;
        }
    

    return 0;
}