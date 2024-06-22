/* Un negocio de perfumería efectúa descuentos en sus ventas según el importe de las mismas, con la
siguiente escala:
• menor a 50 pesos el 3.5 %
• entre 50 y 150 pesos el 10 %
• entre 151 y 300 pesos el 20 %.
• mayor a 300 pesos el 25 %
Confeccionar un programa que:
a. Solicite un importe y calcule el descuento a efectuar y el importe neto a cobrar, con mensajes
aclaratorios.
b. Informe el importe promedio de todas las ventas realizadas.
Se debe contemplar que se puedan ingresar varios importes y para finalizar se ingresa un valor negativo o
cero.
 */

#include <stdio.h>
#include <stdlib.h>  


int main() {

    double importe_total_venta = 0;
    double importe;
    double importe_promedio = 0;
    int cantidad = 0;

    while (1) {
        printf("Ingrese el valor de su importe o 0 si desea finalizar: ");
        scanf("%lf", &importe);
        if (importe <= 0) {
            break;
        }

        if (importe < 50) {
            ++cantidad;
            importe_total_venta += importe * 0.965;
            printf("Importe neto a cobrar: %.2f\n", importe_total_venta);
        } else if (importe >= 50 && importe <= 150) {
            ++cantidad; 
            importe_total_venta += importe * 0.90;
            printf("Importe neto a cobrar: %.2f\n", importe_total_venta);
        } else if (importe >= 151 && importe <= 300) {
            ++cantidad;
            importe_total_venta += importe * 0.80;
            printf("Importe neto a cobrar: %.2f\n", importe_total_venta);
        } else if (importe > 300) {
            ++cantidad;
            importe_total_venta += importe * 0.75;
            printf("Importe neto a cobrar: %.2f\n", importe_total_venta);
        }
    }
    
    if (cantidad > 0) {
        importe_promedio += importe_total_venta / cantidad;
        printf("Importe promedio de las ventas: %.2f\n", importe_promedio);
    } else {
        printf("No se ingresaron importes válidos.\n");
    }

    return 0;
}