#include <stdio.h>

int main (void)
{
    char codigo;
    float importeTotal;
    float efectivo, tarjeta, cheque, totalVenta;
    efectivo = tarjeta = cheque = totalVenta = 0.0;

    do {
        printf("Ingrese el importe total y el código (F para finalizar): ");
        scanf("%f", &importeTotal);
        scanf(" %c", &codigo);

        /* if (codigo == 'F' || codigo == 'f') { */
        /*     return 0; */
        /* } */

        if (codigo == 'C' || codigo == 'c') {
            totalVenta += importeTotal * 1.20;
            cheque += importeTotal * 1.20;
        } else if (codigo == 'E' || codigo == 'e') {
            totalVenta += importeTotal * 0.90;
            efectivo += importeTotal * 0.90;
        } else if (codigo == 'T' || codigo == 't') {
            tarjeta += importeTotal * 1.12;
            totalVenta += importeTotal * 1.12;
        }

    } while (codigo != 'F');

    float iva = totalVenta * 0.21;

    printf("Efectivo en caja:\t\t$%.2f\n", efectivo);
    printf("Ventas con Tarjeta de Crédito:  $%.2f\n", tarjeta);
    printf("Ventas con cheque:\t\t$%.2f\n", cheque);
    printf("Total de Venta:\t\t\t$%.2f\n", totalVenta);
    printf("Importe del IVA:\t\t$%.2f\n", iva);

    return 0;
}
