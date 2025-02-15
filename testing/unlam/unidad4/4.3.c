#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n1, n2, n3;

    printf("Ingrese el primer número: ");
    scanf("%d", &n1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &n2);
    printf("Ingrese el tercer número: ");
    scanf("%d", &n3);

    if (n1 + n2 == n3) {
        printf("El tercer número es la suma de los dos primeros.");
    } else if (n1 + n3 == n2) {
        printf("El segundo número es la suma del primero con el tercero.");
    } else if (n2 + n3 == n1) {
        printf("El primer número es la suma de los dos últimos.");
    } else {
        printf("Ningún número es la suma de los otros dos.");
    }

    return 0;
}
