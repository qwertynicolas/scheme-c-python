/*Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%. Confeccionar un
programa que recibiendo el precio original y un código que indica si es o no con descuento, informe el
precio final (0 no aplica el descuento y 1 aplica el descuento).*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float articulo, precio_final;
    int descuento;
    int codigo;

    printf("Indique el precio de su producto: ");
    scanf("%f", &articulo);
    printf("¿Cuenta esté producto con un descuento? Seleccione 0 si no tiene y 1 si es que tiene ");
    scanf("%d", &codigo);

    if (codigo == 0) { //cuestionable si es necesario o no el uso de if acá, whatever, if it compiles then it's good
        precio_final = articulo;    

    } else if (codigo == 1) {
        descuento = articulo * 0.20;
        precio_final = articulo - descuento;
    
    } else {
        printf("El código es inválido\n");
        return 1;
    }

    printf("El artículo cuesta: %.2f", precio_final);
    return 0;
}