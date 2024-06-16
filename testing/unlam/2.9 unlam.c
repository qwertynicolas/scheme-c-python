/* Confeccionar un programa que ingrese un valor expresado en Kilobyte (KiB) y lo informe expresado en:
TiB, GiB, MiB, con leyendas aclaratorias. (1MiB = 1024 KiB; 1GiB = 1024 MiB; 1TiB = 1024 GiB)*/

#include <stdio.h>
#include <stdlib.h>

int main () {

    int kib;
    double mib, gib, tib;

    printf("Ingrese un valor en KiB (Kilobyte): ");
    scanf("%d", &kib);

    mib = kib / 1024.0;
    gib = mib / 1024.0; 
    tib = gib / 1024.0;

    printf("El valor en MiB (Megabyte) es: %.2f\n", mib);
    printf("El valor en GiB (Gigabyte) es: %.2f\n", gib);
    printf("El valor en TiB (Terabyte) es: %.2f\n", tib);

    return 0;
    

}