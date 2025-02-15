#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int kib;

    printf("Ingrese un valor en KiB: ");
    scanf("%d", &kib);

    int mib = kib / 1024;
    int gib = mib / 1024;
    int tib = gib / 1024;

    printf("Valor en MiB: %d\n", mib);
    printf("Valor en GiB: %d\n", gib);
    printf("Valor en TiB: %d\n", tib);

    return 0;
}
