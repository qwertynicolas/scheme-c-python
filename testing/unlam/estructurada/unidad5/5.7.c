#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char descripcion[31];
    float precio;
} Productos;

int main(void)
{
    Productos producto;
    Productos *pAp;

    printf("Ingrese el código del producto: ");
    scanf("%d", &producto.codigo);
    getchar();

    printf("Ingrese la descripción del producto: ");
    fgets(producto.descripcion, 31, stdin);

    size_t large = strlen(producto.descripcion);

    if (large > 0 && producto.descripcion[large-1] == '\n')
        producto.descripcion[large-1] = '\0';

    printf("Ingrese el precio del producto: ");
    scanf("%f", &producto.precio);

    pAp = &producto;

    printf("Codigo: %d\n", pAp->codigo);
    printf("Descripción: %s\n", pAp->descripcion);
    printf("Precio: %.2f\n", pAp->precio);

    return 0;
}
