#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i, k;

    for (i = 1; i <= 9; ++i) {
        for (k = 1; k <= 9; ++k) {
            printf("%02d ", i*k);
        }
        printf("\n");
    }
}
