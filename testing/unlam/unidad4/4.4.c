#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    float n1, n2, n3;

    printf("Ingrese el primer número: ");
    scanf("%f", &n1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &n2);
    printf("Ingrese el tercer número: ");
    scanf("%f", &n3);

    if (n1 > n3 && n2 > n3) {
        printf("MAYORES AL TERCERO");
    } else if (n1 == n2 && n1 == n3) {
        printf("TRES IGUALES");
    } else if (n1 < n3 || n2 < n3) {
        printf("ALGUNO ES MENOR");
    }

    return 0;
}
