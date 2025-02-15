#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int  i, k;
    /* int sum = 0; */

    for (i = 2; i <= 9000; ++i) {
       int sum = 0;
        for (k = 1; k < i; ++k) {
            if (i % k == 0) {
                sum += k;
            }
        }

        if (sum == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}
