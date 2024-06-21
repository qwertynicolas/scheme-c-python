/* Ingresar N artículos (códigos) y sus correspondientes precios. Indicar el código del artículo más caro y el
precio del más barato. NOTA: todos los artículos tienen precios distintos. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    double precio; // double en caso de que se ingrese un número con o sin decimales, float necesita si o si un número con decimales
    int articulo, codigo;
    float precio_barato = 0;
    int codigo_caro;

    printf("Ingrese la cantidad de articulos que desea comprar: ");
    scanf("%d", &articulo);

    for (int i = 0; i < articulo; ++i) {
        printf("Ingrese el código del artículo Nº%d: ", i + 1);
        scanf("%d", &codigo);
        printf("Ingrese el precio del artículo Nº%d: ", i + 1);
        scanf("%lf", &precio);

        if (i == 0 || precio > precio_caro) {
            codigo_caro = codigo;
        }

        if (i == 0 || precio < precio_barato) {
            precio_barato = precio;
        }
    }

    printf("El código del artículo más caro es %d\n", codigo_caro);
    printf("El precio del artículo más barato es %.2f\n", precio_barato);

    return 0;
}