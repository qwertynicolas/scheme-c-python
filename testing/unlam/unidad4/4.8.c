#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n1,n2;

    printf("Ingrese el primer número: ");
    scanf("%d", &n1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &n2);

    if ((n1 % n2) == 0) {
        printf("El primero es divisible por el segundo.");
    }

    return 0;
}
