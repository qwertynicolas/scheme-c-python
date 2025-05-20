#include <stdio.h>
#include <strings.h>
#include <string.h>

typedef struct {
    char codigo[6];
    float precio;
    char descripcion[31];
    int unidadesVendidas;
    float importeTotal;
} Producto;

void show(Producto productos[], int size)
{
    int i;

    printf("\n");
    printf("DESCRIPCIÓN \t CANTIDAD UNIDADES \t IMPORTE TOTAL\n");
    printf("            \t        VENDIDAS   \t      VENDIDO\n");
    for(i = 0; i < size; ++i) {
        printf("%10s  %3d \t  $%6.2f \n", productos[i].descripcion, productos[i].unidadesVendidas, productos[i].importeTotal);
    }
}

int search(Producto productos[], char codigo[], int size)
{
    int i;

    for (i = 0; i < size; ++i) {
        if (strcasecmp(codigo, productos[i].codigo) == 0) {
            return i;
        }
    }

    return -1;
}

void remove_newline(char str[], int size)
{
   int i, change;
   i = change = 0;

   while (i < size && change == 0) {
       if (str[i] == '\n') {
           str[i] = '\0';
           change = 1;
       } else {
           ++i;
       }
   }
}

int main(void)
{
    Producto productos[50] = {0};
    char codigo[6];
    int i = 0;
    int posicion;
    float precio;

    do {
        printf("Ingrese un código de producto (5 caracteres): ");
        fgets(codigo, 6, stdin);
        remove_newline(codigo, 6);
        while (getchar() != '\n');

        while((posicion = search(productos, codigo, i)) != -1) {
            printf("El código ingresado es un valor repetido. Use uno nuevo: ");
            fgets(codigo, 6, stdin);
            remove_newline(codigo, 6);
            while (getchar() != '\n');
        }

        printf("Ingrese el precio del producto: ");
        scanf("%f", &precio);
        while (getchar() != '\n');

        while (precio <= 0) {
            printf("El precio ingresado no es válido. Intente nuevamente: ");
            scanf("%f", &precio);
            while (getchar() != '\n');
        }

        printf("Ingrese la descripcion del producto (FIN para finalizar): ");
        fgets(productos[i].descripcion, 31, stdin);
        remove_newline(productos[i].descripcion, 31);

        if (strcasecmp(productos[i].descripcion, "FIN") != 0) {
            strcpy(productos[i].codigo, codigo);
            productos[i].precio = precio;

            printf("Ingrese la cantidad de unidades vendidas el mes anterior: ");
            scanf("%d", &productos[i].unidadesVendidas);
            while (getchar() != '\n');

            while (productos[i].unidadesVendidas < 0) {
                printf("Ingrese un valor válido: ");
                scanf("%d", &productos[i].unidadesVendidas);
                while (getchar() != '\n');
            }

            printf("Ingrese el importe total vendido del mes anterior: ");
            scanf("%f", &productos[i].importeTotal);
            while (getchar() != '\n');

            while (productos[i].importeTotal < 0) {
                printf("El valor ingresado no es válido. Intente nuevamente: ");
                scanf("%f", &productos[i].importeTotal);
                while (getchar() != '\n');
            }

            ++i;

        } 
    } while (i < 50 && strcasecmp(productos[i].descripcion, "FIN") != 0);

    printf("\nIniciando programa de carga...\n");
    int cantidadPedida = -1;

    while (cantidadPedida != 0) {
        printf("Ingrese el código de producto: ");
        fgets(codigo, 6, stdin);
        remove_newline(codigo, 6);
        while (getchar() != '\n');

        while ((posicion = search(productos, codigo, i)) == -1) {
            printf("El código ingresado no es válido. Intente nuevamente: ");
            fgets(codigo, 6, stdin);
            remove_newline(codigo, 6);
            while (getchar() != '\n');
        }

        printf("Ingrese la cantidad pedida (0 para finalizar): ");
        scanf("%d", &cantidadPedida);
        while (getchar() != '\n');

        while (cantidadPedida < 0) {
            printf("La cantidad ingresada no es válida. Intente nuevamente: ");
            scanf("%d", &cantidadPedida);
            while (getchar() != '\n');
        }

        productos[posicion].unidadesVendidas += cantidadPedida;
        productos[posicion].importeTotal += cantidadPedida * productos[posicion].precio;
    }

    show(productos, i);

    return 0;
}
