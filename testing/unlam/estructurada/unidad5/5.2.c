#include <stdio.h>

int main(void)
{
    int x = 3, y = 4;
    int *px, *py;
    px = &x;
    py = &y;

    printf("%d\n", *px + *py);

    return 0;


}
