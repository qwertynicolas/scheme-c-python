#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int numero;

    printf("Ingrese un número de 4 cifras: ");
    scanf("%d", &numero);

    int firstDigit = numero / 1000;

    numero -= (1000 * firstDigit);

    int secondDigit = numero / 100;

    numero -= (100 * secondDigit);

    int thirdDigit = numero / 10;

    numero -= (10 * thirdDigit);

    int sumaTotal = firstDigit + secondDigit + thirdDigit + numero;

    int mod9 = sumaTotal % 9;

    printf("Suma total (mod 9): %d\n", mod9);

    return 0;
}
