#include <stdio.h>

int main (void)
{
    int i, k, j, n;
    int ayuda = 0;

    printf("Ingrese la cantidad de líneas: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        for (k = n-i; k != 0; --k) {
            printf(" ");
        }

        for (j = 1 + ayuda; j != 0 ; --j) {
            printf("*");
        }

        printf("\n");
        ayuda += 2;
    }

    printf("Ayuda: %d", ayuda);

    return 0;
}
