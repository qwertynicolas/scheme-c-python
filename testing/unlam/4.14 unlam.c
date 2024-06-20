/* La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la siguiente
escala:

a. menor de $55 el descuento es del 4.5%
b. entre $55 y $100 el descuento es del 8%
c. más de $100 el descuento es del 10.5%
Confeccionar un programa que reciba un importe e informe: el descuento y el precio neto a cobrar, con
mensajes aclaratorios.

 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int importe;
    int precio_final;

    printf("Ingrese el importe de su compra: ");
    scanf("%d", &importe); // deberia usarse una variablea double acá para habilitar la posibilidad de poner numeros con décimales

    if (importe < 55) {
        precio_final = importe - (importe * 0.045); // podría crear otra variable en la cual calcule el descuento por separado y así hacer que sea más concisa la cuenta
        printf("El descuente es del 4.5%%. Precio a cobrar: $%d\n", precio_final);
    } else if (importe >= 55 && importe <= 100) {
        precio_final = importe - (importe * 0.08);
        printf("El descuente es del 8%%. Precio a cobrar: $%d\n", precio_final);
    } else if (importe > 100) {
        precio_final = importe - (importe * 0.105);
        printf("El descuento es del 10.5%%. Precio a cobrar: $%d\n", precio_final);
    } else {
        printf("El producto no cuenta con descuento."); // para cerrar el ciclo (creo) no sé realmente si es necesario, anyways jamás va a llegar
    }

    return 0;
}