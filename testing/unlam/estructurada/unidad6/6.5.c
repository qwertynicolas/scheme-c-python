#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    float precio;
    char descripcion[51];
} Producto;

int search(FILE*, int);
void mostrar();
void exportarCSV();
void borrarRegistro();

int main(void)
{
    FILE *pf;
    Producto productos;
    int codigo;
    char ver, actualizar, borrar;
    int posicion;

    printf("¿Desea visualizar la lista de productos? (S/N): ");
    scanf(" %c", &ver);

    if (ver == 'S' || ver == 's') {
        mostrar();
    }

    printf("¿Desea actualizar la lista de precios? (S/N): ");
    scanf(" %c", &actualizar);

    if (actualizar == 'S' || actualizar == 's') {
        printf("Iniciando programa de actualización...\n");

        pf = fopen("PRODUCTOS.dat", "r+b");
        if (pf == NULL) {
            printf("Error al abrir el archivo.\n");
            getchar();
            exit(1);
        }

        printf("Ingrese el código del producto: ");
        scanf("%d", &codigo);

        while(codigo != 0) {
            while ((posicion = search(pf, codigo)) == -1) {
                printf("El código ingresado no es válido. Intente nuevamente: ");
                scanf("%d", &codigo);
            }

            fseek(pf, sizeof(Producto) * posicion, SEEK_SET);
            fread(&productos, sizeof(Producto), 1, pf);

            printf("Precio actual: %.2f\n", productos.precio);
            printf("Ingrese el nuevo precio: ");
            scanf("%f", &productos.precio);

            while (productos.precio < 0) {
                printf("El precio no es válido. Intente nuevamente: ");
                scanf("%f", &productos.precio);
            }

            fseek(pf, sizeof(Producto) * posicion, SEEK_SET);
            fwrite(&productos, sizeof(Producto), 1, pf);
            /* fseek(pf, 0, SEEK_CUR); */

            printf("Ingrese un nuevo código o 0 si desea finalizar: ");
            scanf("%d", &codigo);
        }

        fclose(pf);
    }

    printf("¿Desea borrar algún registro? (S/N): ");
    scanf(" %c", &borrar);

    if (borrar == 'S' || borrar == 's') {
        borrarRegistro();
    }

    exportarCSV();
    return 0;

}

void mostrar()
{
    FILE *pf;
    Producto lista;

    pf = fopen("PRODUCTOS.dat", "rb");
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

    printf("\n");

    fclose(pf);
}

int search(FILE *pf, int codigo)
{
    Producto producto;
    int i = 0, posicion = -1;
    rewind(pf);

    fread(&producto, sizeof(Producto), 1, pf);
    while(!feof(pf) && posicion == -1) {
        if (producto.codigo == codigo) {
            posicion = i;
        } else {
            i++;
            fread(&producto, sizeof(Producto), 1, pf);
        }
    }

    return posicion;
}

void exportarCSV()
{
    FILE *binario, *csv;
    Producto productos;

    binario = fopen("PRODUCTOS.dat", "rb");
    if (binario == NULL) {
        printf("Error al abrir el archivo binario.\n");
        getchar();
        exit(1);
    }

    csv = fopen("productos.csv", "wt");
    if (csv == NULL) {
        printf("Error al crear archivo csv.\n");
        getchar();
        exit(1);
    }

    fprintf(csv, "Codigo;Precio;Descripción\n");

    fread(&productos, sizeof(Producto), 1, binario);
    while(!feof(binario)) {
        fprintf(csv, "%d;%.2f;%s\n", productos.codigo, productos.precio, productos.descripcion);
        fread(&productos, sizeof(Producto), 1, binario);
    }

    fclose(binario);
    fclose(csv);

    printf("Producto exportado como .csv correctamente.\n");
}

void borrarRegistro()
{
    FILE *pf, *pftemp;
    Producto productos;
    int codigo, posicion;

    pf = fopen("PRODUCTOS.dat", "rb");
    pftemp = fopen("PRODUCTOS.tmp", "wb");

    if (pf == NULL) {
        printf("Error al abrir el archivo original.\n");
        getchar();
        exit(1);
    }

    if (pftemp == NULL) {
        printf("Error al crear archivo temporal.\n");
        getchar();
        exit(1);
    }

    printf("Ingrese el código del registro a borrar: ");
    scanf("%d", &codigo);

    while (codigo != 0) {
        while ((posicion = search(pf, codigo)) == -1) {
            printf("El código ingresado no es válido. Intente nuevamente: ");
            scanf("%d", &codigo);
        }

        rewind(pf);
        fread(&productos, sizeof(Producto), 1, pf);
        while(!feof(pf)) {
            if (productos.codigo != codigo) {
                fwrite(&productos, sizeof(Producto), 1, pftemp);
            } else {
                printf("Registro con código %d eliminado\n", codigo);
            }

            fread(&productos, sizeof(Producto), 1, pf);
        }

        printf("Ingrese un nuevo código a borrar o 0 si desea finalizar: ");
        scanf("%d", &codigo);
    }

    fclose(pf);
    fclose(pftemp);

    remove("PRODUCTOS.dat");
    rename("PRODUCTOS.tmp", "PRODUCTOS.dat");

}
