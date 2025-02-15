#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int precio, codigo;

    printf("Ingrese el precio del producto: ");
    scanf("%d", &precio);
    printf("Ingrese el código de descuento (0 ó 1): ");
    scanf("%d", &codigo);

    float precioTotal = precio - (precio * 0.20 * codigo);

    printf("Precio total: %.2f", precioTotal);

    return 0;
}
