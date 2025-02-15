#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int num1, num2;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    printf("Suma: %d\n", num1 + num2);
    printf("Resta: %d\n", num1 - num2);
    printf("Producto: %d\n", num1 * num2);
    printf("Cociente: %.2f\n", (float) num1 / num2);
    printf("Resto: %d\n", num1 % num2);

    return 0;
}
