#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int codigo;
    char descripcion[31];
    float precioUnitario;
    char tipo;
} Producto;

void mostrarProductos();
void incrementarPrecios(char, int);

int main(void)
{
    mostrarProductos();
    incrementarPrecios('T', 20);

    printf("\n\n---Precios actualizados---\n");
    mostrarProductos();

    return 0;
}

void incrementarPrecios(char tipo, int aumento)
{
    FILE *ap;
    Producto producto;
    ap = fopen("productos.dat", "r+b");
    if (ap == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    fread(&producto, sizeof(Producto), 1, ap);
    while (!feof(ap)) {
        if (toupper(producto.tipo) == toupper(tipo)) {
            producto.precioUnitario += (producto.precioUnitario * aumento) / 100;
            fseek(ap, sizeof(Producto) * -1, SEEK_CUR);
            fwrite(&producto, sizeof(Producto), 1, ap);
            fseek(ap, 0, SEEK_CUR);
        }

        fread(&producto, sizeof(Producto), 1, ap);
    }
    fclose(ap);
}

void mostrarProductos()
{
    FILE *ap;
    Producto producto;
    ap = fopen("productos.dat", "rb");
    if (ap == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    printf("%6s %-30s %8s %4s", "CODIGO", "DESCRIPCION", "PRECIO", "TIPO");
    fread(&producto, sizeof(Producto), 1, ap);

    while (!feof(ap)) {
        printf("\n%6d %-30s %8.2f %4c", producto.codigo, producto.descripcion, producto.precioUnitario, producto.tipo);
        fread(&producto, sizeof(Producto), 1, ap);
    }
    fclose(ap);
}
