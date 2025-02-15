#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n;

    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &n);

    int i, k;

    for (i = 1; i <= n; ++i) {
        for (k = 0; k < i; ++k) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
