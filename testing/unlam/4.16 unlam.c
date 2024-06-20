/* Un negocio vende distintos artículos identificados por un código, según se muestra:
• código 1; 10; 100: 10 pesos la unidad.
• código 2; 22; 222: 7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
• código 3; 33: 3 pesos la unidad. Si la compra es por más de 10 unidades se hace un descuento del
10% sobre el total de la compra.
• código 4; 44: 1 peso la unidad.
Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a comprar y se
informe el importe de la compra, con las siguientes leyendas:
ARTÍCULO xxxxx CANTIDAD xxxx IMPORTE A PAGAR $ xxxx.xx */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int articulo, cantidad;
    double importe;

    printf("Ingrese el código del artículo que desea comprar: ");
    scanf("%d", &articulo);
    printf("Ingrese la cantidad que desea comprar: ");
    scanf("%d", &cantidad);

    if (articulo == 1 || articulo == 10 || articulo == 100) {
        importe = cantidad * 10;
    } else if (articulo == 2 || articulo == 22 || articulo == 222) {
        importe = ((cantidad / 10) * 65) + ((cantidad % 10) * 7); 
    } else if (articulo == 3 || articulo == 33 && cantidad < 10) {
        if (cantidad > 10) {
            importe = (cantidad * 3) * 0.9;
        } else {
            importe = cantidad * 3;
        }
    } else if (articulo == 4 || articulo == 44) {
        importe = cantidad * 1;
    }
     else {
        printf("El código no es válido.\n");
        return 1;
    }
    printf("ARTÍCULO: %d\t CANTIDAD: %d\t IMPORTE A PAGAR: $%.2f\n", articulo, cantidad, importe);
    
    return 0;
}