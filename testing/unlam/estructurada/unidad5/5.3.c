#include <stdio.h>

void cargarValores(int *px, float *py, char *pz)
{
    printf("Ingrese un entero: ");
    scanf("%d", px);

    printf("Ingrese un punto-flotante: ");
    scanf("%f", py);

    printf("Ingrese un char: ");
    scanf(" %c", pz);
}

int main(void)
{
    int x;
    float y;
    char z;

    cargarValores(&x, &y, &z);
    printf("Entero: %d\n", x);
    printf("Punto flotante: %.2f\n", y);
    printf("Char: %c\n", z);

    return 0;
}
