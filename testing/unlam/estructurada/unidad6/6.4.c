#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    float precio;
    char descripcion[51];
} Producto;

void mostrar();

int main(void)
{
    FILE *pf;
    Producto listaNueva;
    int aumento;

    pf = fopen("PRECIOS.dat", "r+b");
    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    printf("Ingrese el porcentaje de aumento: ");
    scanf("%d", &aumento);

    fread(&listaNueva, sizeof(Producto), 1, pf);
    while (!feof(pf)) {
        listaNueva.precio += (listaNueva.precio * aumento) / 100;
        fseek(pf, sizeof(Producto)*-1, SEEK_CUR); // uno para atrás
        fwrite(&listaNueva, sizeof(Producto), 1, pf);
        fseek(pf, 0, SEEK_CUR); // flushing the buffer

        fread(&listaNueva, sizeof(Producto), 1, pf);
    }
    fclose(pf);

    mostrar();

    return 0;
}

void mostrar()
{
    FILE *pf;
    Producto lista;

    pf = fopen("PRECIOS.dat", "rb");
    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    fread(&lista, sizeof(Producto), 1, pf);

    while(!feof(pf)) {
        printf("Codigo: %d\n", lista.codigo);
        printf("Precio: %.2f\n", lista.precio);
        fread(&lista, sizeof(Producto), 1, pf);
    }

    fclose(pf);
}
