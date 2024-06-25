/* Ejercicio 2: Gestión de Inventarios

Crea un programa que permita gestionar el inventario de una tienda. El programa debe permitir al usuario agregar productos, eliminar productos y mostrar el inventario.
Requisitos:

    Crear una función para mostrar el menú y retornar la opción elegida.
    Crear funciones para agregar un producto, eliminar un producto y mostrar el inventario.
    Validar que el nombre del producto no esté vacío y que la cantidad sea un número positivo. */

#include <string.h>
#include <stdio.h>

typedef struct {
    char nombre[50];
    int cantidad;
} Producto; // el nombre de este struct

void mostrar_menu() {// el inventario al inicio del programa va a estar vacío, la primera opción si o si necesita ser la de agregar productos
// char[] nombreProducto, 

        printf("Menú de opciones\n");
        printf("----- -- -----\n");
        printf("(1) Agregar productos\n");
        printf("(2) Eliminar productos\n");
        printf("(3) Mostrar el inventario\n");
        printf("(4) Finalizar\n");
        printf("Seleccione la opción deseada: ");

}

void agregar_producto (Producto inventario[], int *num_productos) {
    printf("Ingrese el nombre del producto: ");
    scanf("%s", inventario[*num_productos].nombre);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &inventario[*num_productos].cantidad);
    (*num_productos)++;
}

void eliminar_productos (Producto inventario[], int *num_productos) {
    char nombre[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);
    for (int i = 0; i < *num_productos; ++i) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            for (int j = i; j < *num_productos - 1; ++j) {
                inventario[j] = inventario[j + 1];
            }

            (*num_productos)--;
            printf("Producto eliminado.\n");
            return; 
        }
    }
    printf("Producto no encontrado.\n");
}


void mostrar_inventario (Producto inventario[], int num_productos) {
    printf("Inventario:\n");
    for (int i = 0; i < num_productos; ++i) {
        printf("Producto: %s. Cantidad: %d\n", inventario[i].nombre, inventario[i].cantidad);
    }
}

int main() {

    Producto inventario[100];
    int num_productos = 0;
    int opcion;

    while (1) {
        mostrar_menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1 :
            agregar_producto(inventario, &num_productos);
            break;
            case 2 :
            eliminar_productos(inventario, &num_productos);
            break;
            case 3 :
            mostrar_inventario(inventario, num_productos);
            break;
            case 4 :
            printf("Saliendo del programa...\n");
            return 0;
            default : printf("Opción no válida.\n");
        }

        printf("Presione Enter para continuar...\n");
        getchar();
        getchar();
        
    }

    return 0;
}