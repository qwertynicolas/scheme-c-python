#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i;
    int suma = 0; // ++i == i = i + 1

    for (i = 100; i >= 50; i -= 5) {
        suma += i;
    }

    printf("%d", suma);

    return 0;
}
