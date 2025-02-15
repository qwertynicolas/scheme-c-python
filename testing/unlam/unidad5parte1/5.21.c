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

    /* ayuda = 0; */

    for (i = n-1; i != 0; --i) {
        for (k = i; k < n; ++k) {
            printf(" ");
        }

        for (j = ayuda - 3; j != 0; --j) {
            printf("*");
        }

        printf("\n");
        ayuda -= 2;
    }

    return 0;
}
