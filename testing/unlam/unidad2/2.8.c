#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int ddmmaa;

    printf("Ingrese una fecha en formato dd/mm/aa: ");
    scanf("%d", &ddmmaa);

    int dd = ddmmaa / 10000;
    int mm = (ddmmaa / 100) - (dd * 100);
    int aa = ddmmaa - ((dd * 10000) + (mm * 100));

    printf("Formato aa/mm/dd: ");
    printf("%02d/%02d/%02d", aa, mm, dd);

    return 0;
}
