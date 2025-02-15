#include <stdio.h>

int main (void)
{
    int i = 2;
    int k;

    printf("1 2 ");

    /* while (i < 600) { */

    /*     k = 2; */
    /*     i *= k; */
    /*     printf("%d ", i); */
    /* } */

    do {
        k = 2;
        i *= k;
        printf("%d ", i);

    } while (i <= 256);

    return 0;
}
