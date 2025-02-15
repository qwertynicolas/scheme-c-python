#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n, i;
    int suma = 0;

    printf("Ingrese un número: ");
    scanf("%d", &n);

    for (i = 0; i <= n; ++i) {
        suma += i;
    }

    printf("Sumatoria: %d", suma);

    return 0;
}
