#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int producto;

    printf("Ingrese el número del producto: ");
    scanf("%d", &producto);

    if (producto < 1200 || producto > 90000) {
        printf("FUERA DE CATALAGO.");
        return 0;
    }

    if (producto >= 12121 && producto <= 18081) {
        printf("El producto es defectuoso.");
    } else if (producto >= 30012 && producto <= 45565) {
        printf("El producto es defectuoso.");
    } else if (producto >= 67000 && producto <= 68000) {
        printf("El producto es defectuoso.");
    } else {
        printf("El producto NO es defectuoso.");
    }

    return 0;
}
