#include <stdio.h>

int main (void)
{
    int n;
    int counter = 0;

    printf("Ingrese la cantidad de números primos a buscar: ");
    scanf("%d", &n);

    int i, j, k;
    int notPrime = 0;

    i = 2;

    do {

        for (j = i-1; j > 0; --j) {
            k = i % j;

            if (k == 0 && j != 1) {
                ++notPrime;
            }

            if (j == 1 && notPrime == 0) {
                ++counter;
                printf("%d ", i);
            }

        }

        notPrime = 0;
        ++i;

    } while (counter < n);

    return 0;
}
