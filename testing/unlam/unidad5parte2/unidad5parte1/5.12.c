#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i, n;
    int factorial = 1;

    printf("Ingrese el número: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }

    printf("Factorial: %d", factorial);

    return 0;

}
