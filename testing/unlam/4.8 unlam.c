/* Realizar un programa que ingrese dos números e indique si el primer número es divisible por el segundo. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b;

    printf("Ingrese el primer número a evaluar: ");
    scanf("%d", &a);
    printf("Ingrese el segundo número a evaluar: ");
    scanf("%d", &b);

    if (b != 0) {
        if (a % b == 0) {
            printf("El primer número es divisible por el segundo.\n");
        } else {
            printf("El primer número NO es divisible por el segundo.\n");
        }
    } else {
        printf("División por cero no definida.\n");
    }

    return 0;
}
