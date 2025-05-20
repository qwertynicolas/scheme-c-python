#include <stdio.h>
#include <strings.h>
#include <string.h>

#define CLEAR_BUFFER() while ((c = getchar()) != '\n' && c != EOF)

typedef struct {
    char codigo[4];
    float precioUnitario;
    int ventas;
} Producto;

void sort(Producto productos[], int size)
{
    int i, swap;
    Producto temp;

    do {
        swap = 0;
        for (i = 0; i < size-1; i++) {
            if (strcasecmp(productos[i].codigo, productos[i+1].codigo) > 0) {
                temp = productos[i];
                productos[i] = productos[i+1];
                productos[i+1] = temp;
                swap = 1;
            }
        }
    } while (swap);
}

void remove_newline(char str[], int size)
{
    int i = 0;
    int change = 0;

    while (i < size && change == 0) {
        if (str[i] == '\n') {
            str[i] = '\0';
            change = 1;
        } else {
            i++;
        }
    }
}

int search(Producto productos[], char codigoBuscado[], int size)
{
    int i;

    for (i = 0; i < size; i++) { // if size = 0 it returns -1 instantly
        if (strcasecmp(codigoBuscado, productos[i].codigo) == 0)
            return i;
    }

    return -1;
}

int main(void)
{
    char codigo[4];
    int i = 0;
    int c;
    Producto productos[50] = {0};

    do {
        printf("Ingrese el código del producto o FIN para finalizar: ");
        fgets(codigo, 4, stdin);
        remove_newline(codigo, 4);
        CLEAR_BUFFER();

        while (search(productos, codigo, i) != -1) {
            printf("Código repetido. Use otro valor: ");
            fgets(codigo, 4, stdin);
            remove_newline(codigo, 4);
            CLEAR_BUFFER();
        }

        if (strcasecmp(codigo, "FIN") != 0 && i < 50) {

            printf("Ingrese el precio por unidad del producto: ");
            scanf("%f", &productos[i].precioUnitario);
            CLEAR_BUFFER();

            while (productos[i].precioUnitario <= 0) {
                printf("El valor ingresado no es válido. Intente nuevamente: ");
                scanf("%f", &productos[i].precioUnitario);
                CLEAR_BUFFER();
            }

            strcpy(productos[i].codigo, codigo);

            i++;
        }
    } while (strcasecmp(codigo, "FIN") != 0 && i < 50);

   float recaudacionTotal = 0.0;
   int posicionCodigo;
   int unidadesVendidas;

   printf("\nIniciando programa de carga...\n");

   do {
       printf("Ingrese el código del producto: ");
       fgets(codigo, 4, stdin);
       remove_newline(codigo, 4);
       CLEAR_BUFFER();

       while((posicionCodigo = search(productos, codigo, i)) == -1) {
           printf("Código no válido. Intente nuevamente: ");
           fgets(codigo, 4, stdin);
           remove_newline(codigo, 4);
           CLEAR_BUFFER();
       }

       printf("Ingrese la cantidad de unidades vendidas (0 para finalizar): ");
       scanf("%d", &unidadesVendidas);
       CLEAR_BUFFER();

       if (unidadesVendidas != 0) {
           while (unidadesVendidas < 0) {
               printf("La cantidad ingresada no es válida. Intente nuevamente: ");
               scanf("%d", &unidadesVendidas);
               CLEAR_BUFFER();
           }

           recaudacionTotal += productos[posicionCodigo].precioUnitario * unidadesVendidas;
           productos[posicionCodigo].ventas += unidadesVendidas;
       }
   } while (unidadesVendidas != 0);

   int j, menorVentas = productos[0].ventas;
   char menorVendido[4];
   strcpy(menorVendido, productos[0].codigo);

   for (j = 1; j < i; j++) {
       if (productos[j].ventas < menorVentas) {
           menorVentas = productos[j].ventas;
           strcpy(menorVendido, productos[j].codigo);
       }
   }

   printf("Recaudación total del día: %.2f\n", recaudacionTotal);
   printf("Producto menor vendido (%d unidades): %s\n", menorVentas, menorVendido);

   sort(productos, i);

   printf("Listado de productos:\n");
   for (j = 0; j < i; j++) {
       printf("Codigo: %s - Precio por unidad: %.2f\n", productos[j].codigo, productos[j].precioUnitario);
   }

   return 0;

}
