/* Confeccionar un programa que permita ingresar 4 números enteros, de a uno por vez y determine el menor
valor y su número de orden. Informe los valores ingresados e identifique al menor con mensaje aclaratorio. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1, num2, num3, num4;
    printf("Ingresar el primer número: ");
    scanf("%d", &num1);
    printf("Ingresar el segundo número: ");
    scanf("%d", &num2);
    printf("Ingresar el tercer número: ");
    scanf("%d", &num3);
    printf("Ingresar el cuarto número: ");
    scanf("%d", &num4);

    if (num1 < num2 && num1 < num3 && num1 < num4) {
        printf("El primer número es el menor.\n");
    } else if (num2 < num1 && num2 < num3 && num2 < num4) {
        printf("El segundo número es el menor.\n");
    } else if (num3 < num1 && num3 < num2 && num3 < num4) {
        printf("El tercer número es el menor.\n");
    } else if (num4 < num1 && num4 < num3 && num4 < num2) {
        printf("El cuarto número es el menor.\n");
    }

    printf("Los valores ingresados fueron: %d, %d, %d, %d.\n", num1, num2, num3, num4);
    return 0;
}