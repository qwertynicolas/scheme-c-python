#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    int stockFaltante;
} Faltante;

typedef struct {
    int codigo;
    char descripcion[51];
    int stock;
} Producto;

int search(FILE*, int);
void mostrar(FILE*);
void stockFaltante (FILE*, FILE*, int, int, int);
void mostrarFaltantes(FILE *);

// hay un bug por usar feof que genera dos entradas con el mismo código en stock faltante
int main(void)
{
    Producto producto;
    FILE *pf, *faltantes;
    int codigo, posicion, cantidad;
    char primeraVez, ver, vender, verFaltantes;

    printf("¿Está ejecutando el programa por primera vez? (S/N): ");
    scanf(" %c", &primeraVez);

    pf = fopen("STOCK.dat", "r+b");

    if (primeraVez == 'S' || primeraVez == 's') {
        faltantes = fopen("FALTANTES.dat", "w+b");
    } else {
        faltantes = fopen("FALTANTES.dat", "a+b");
    }

    if (pf == NULL) {
        printf("Error al abrir el archivo de stock.\n");
        getchar();
        exit(1);
    }

    if (faltantes == NULL) {
        printf("Error al abrir el archivo de faltantes.\n");
        getchar();
        exit(1);
    }

    printf("¿Desea ver una lista de los productos? (S/N): ");
    scanf(" %c", &ver);

    if (ver == 'S' || ver == 's') {
        mostrar(pf);
    }

    printf("¿Desea iniciar el programa de ventas? (S/N): ");
    scanf(" %c", &vender);

    if (vender == 'S' || vender == 's') {
        printf("Iniciando programa de ventas...\n\n");
        printf("Ingrese el código del producto a vender: ");
        scanf("%d", &codigo);

        while (codigo != 0) {
            while ((posicion = search(pf, codigo)) == -1) {
                printf("El código ingresado no es válido. Intente nuevamente: ");
                scanf("%d", &codigo);
            }

            fseek(pf, sizeof(Producto) * posicion, SEEK_SET);
            fread(&producto, sizeof(Producto), 1, pf);
            printf("Stock disponible del producto: %d\n", producto.stock);
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &cantidad);

            while (cantidad < 0) {
                printf("La cantidad ingresada no es válida. Intente nuevamente: ");
                scanf("%d", &cantidad);
            }

            if (cantidad <= producto.stock) {
                producto.stock -= cantidad;
                fseek(pf, sizeof(Producto) * posicion, SEEK_SET);
                fwrite(&producto, sizeof(Producto), 1, pf);
            } else {
                stockFaltante(pf, faltantes, codigo, cantidad, posicion);
                producto.stock = 0;
                fseek(pf, sizeof(Producto) * posicion, SEEK_SET);
                fwrite(&producto, sizeof(Producto), 1, pf);
            }

            printf("Ingrese un nuevo código o 0 si desea finalizar: ");
            scanf("%d", &codigo);
        }
    }

    printf("¿Desea ver los productos con stock faltante? (S/N): ");
    scanf(" %c", &verFaltantes);

    if (verFaltantes == 'S' || verFaltantes == 's') {
        mostrarFaltantes(faltantes);
    }

    fclose(pf);
    fclose(faltantes);

    return 0;
}

void stockFaltante(FILE *pf, FILE *faltantes, int codigo, int cantidad, int posicion)
{
    Producto producto;
    Faltante productosFaltantes;
    int flag = 0;

    fseek(pf, sizeof(Producto) * posicion, SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pf);

    rewind(faltantes);

    fread(&productosFaltantes, sizeof(Faltante), 1, faltantes);
    while(!feof(faltantes) && flag == 0) {
        if (productosFaltantes.codigo == codigo)
            flag = 1;
        else
            fread(&productosFaltantes, sizeof(Faltante), 1, faltantes);
    }

    if (flag) {
        productosFaltantes.stockFaltante += cantidad - producto.stock;
        fseek(faltantes, sizeof(Faltante) * -1, SEEK_CUR);
    } else {
        productosFaltantes.codigo = codigo;
        productosFaltantes.stockFaltante = cantidad - producto.stock;
        fseek(faltantes, 0, SEEK_END);
    }

    fwrite(&productosFaltantes, sizeof(Faltante), 1, faltantes);

    printf("El stock no fue suficiente. Cantidad faltante: %d\n", productosFaltantes.stockFaltante);
}

void mostrarFaltantes(FILE *pfaltantes)
{
    Faltante faltantes;
    rewind(pfaltantes); // por si se uso

    fread(&faltantes, sizeof(Faltante), 1, pfaltantes);

    while(!feof(pfaltantes)) {
        printf("Código: %d\n", faltantes.codigo);
        printf("Stock faltante: %d\n", faltantes.stockFaltante);

        fread(&faltantes, sizeof(Faltante), 1, pfaltantes);
    }
}

void mostrar(FILE *pf)
{
    Producto producto;

    fread(&producto, sizeof(Producto), 1, pf);

    while(!feof(pf)) {
        printf("Código: %d\n", producto.codigo);
        printf("Stock restante: %d\n", producto.stock);

        fread(&producto, sizeof(Producto), 1, pf);
    }
    rewind(pf);
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
