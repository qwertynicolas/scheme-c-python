/* Un negocio de venta de granos desea controlar las ventas realizadas. De cada una ingresa el importe total
y un código que indica la forma de pago. El código puede ser:
• C: cheque, 20% de recargo.
• E: efectivo, 10% de descuento.
• T: con tarjeta, 12% de recargo.
Se debe ingresar una F para finalizar el día de venta y arrojar los siguientes totales.
Efectivo en Caja: $ xxxx.xx
Ventas con Tarjeta de Crédito: $ xxxx.xx
Ventas con cheque: $ xxxx.xx
Total de Venta: $ xxxx.xx
Importe del IVA: $ xxxx.xx */


#include <stdio.h>
#include <stdlib.h>

int main() {

    double importe_iva = 0;
    double total_venta = 0;
    double venta_cheque = 0; // codigo C
    double venta_tarjeta = 0; //codigo T
    double efectivo = 0; // codigo E
    double importe;
    char codigo;

    while (1) {

    printf("Ingrese el valor del importe de la venta o 'F' para finalizar: ");
    scanf("%lf", &importe);
    if (importe == 'F') {
        break;
    }

    printf("Ingrese el código de la venta (C, E, T): ");
    scanf(" %c", &codigo);

        total_venta += importe;

        if (codigo == 'C') {
            importe *= 1.20;
            venta_cheque += importe;
        } else if (codigo == 'T') {
            importe *= 1.12;
            venta_tarjeta += importe;
        } else if (codigo == 'E') {
            importe *= 0.9;
            efectivo += importe;
        } else if (codigo == 'F') {
            break;
        } else {
            printf("El código no es válido.\n");
            continue;
        }

        total_venta += importe;
    }

    importe_iva = total_venta * 0.21;

    printf("Efectivo en caja: %.2f\n", efectivo);
    printf("Ventas con tarjeta de crédito: %.2f\n", venta_tarjeta);
    printf("Ventas con cheque: %.2f\n", venta_cheque);
    printf("Total de venta: %.2f\n", total_venta);
    printf("Importe del IVA: %.2f\n", importe_iva);

    return 0;
}