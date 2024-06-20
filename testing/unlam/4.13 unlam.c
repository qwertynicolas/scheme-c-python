/* Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los
números de catálogo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Se desea
confeccionar un programa al que informándole el número de catálogo indique si el artículo es o no
defectuoso. Los artículos del catálogo van desde el 1200 al 90000. Si se ingresa otro número informar
“FUERA DE CATALOGO”. */

#include <stdio.h>
#include <stdlib.h>

int main () {

    int num_catalogo;

    printf("Ingrese el número de catálogo del artículo: ");
    scanf("%d", &num_catalogo);

    if (num_catalogo < 1200 || num_catalogo > 90000) {
        printf("Fuera de catálogo.\n");
        return 1;
    }

    if (num_catalogo >= 12121 && num_catalogo <= 18081) {
        printf("El artículo es defectuoso.\n");
    } else if (num_catalogo >= 30012 && num_catalogo <= 45565) {
        printf("El artículo es defectuoso.\n");
    } else if (num_catalogo >= 67000 && num_catalogo <= 68000) {
        printf("El artículo es defectuoso.\n");
    } else {
        printf("El artículo NO es defectuoso.\n");
    }

    return 0;

}