/* Un negocio de artículos de computación vende DVDs según la siguiente escala de precios:
• sueltos, entre 1 y 9 a $15 c/u.
• la caja de 10 cuesta $120.
• la caja de 50 cuesta $500.

Si la compra excede las 100 unidades se efectúa un descuento del 10%.

NOTA: se aceptan compras entre 1 y 500 DVDs.
Se pide que se ingrese una cantidad de DVDs que se quiere comprar y calcule e informe el importe a pagar.

 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int dvds;
    double importe;

    printf("Ingrese la cantidad de DVDs que desea comprar: ");
    scanf("%d", &dvds);

    if (dvds < 1 || dvds > 500) {
        printf("No se aceptan compras de esa cantidad.\n");
        return 1;
    }

 if (dvds <= 9) {
        importe = dvds * 15;
    } else if (dvds <= 49) {
        importe = (dvds / 10) * 120 + (dvds % 10) * 15;
    } else if (dvds <= 100) {
        importe = (dvds / 50) * 500 + ((dvds % 50) / 10) * 120 + (dvds % 10) * 15; /*
        el primer cálculo es para verificar cuántas cajas de 50 hay y luego multiplicar esa cantidad por 500 (precio de cajas de 50)
        el segundo es para verificar cuántas cajas de 10 hay (primero se verifica la cantidad de cajas que sobraron, por eso la operación de dvds % 50, si ingresaramos
        el número 75, esta operación deberia de dar 25, y al dividirse por 10 daria 2, que son las cajas de 10 que hay en 75 dvds) y hacer lo mismo que con
        las cajas de 50, ocurrirá lo mismo con los dvds separados, el tercero es para verificar cuantos dvds separados hay*/
    } else {
        importe = (dvds / 50) * 500 + ((dvds % 50) / 10) * 120 + (dvds % 10) * 15;
        importe *= 0.9; // por si la cantidad es mayor que 100, se realiza la operación del paso anterior y por último se aplica el descuento
    } 
    
    printf("El importe a pagar es $%.2f\n", importe);

    return 0;
}