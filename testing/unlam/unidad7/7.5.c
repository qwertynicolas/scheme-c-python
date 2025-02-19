#include <stdio.h>

int main (void)
{
    int listaPedidos[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int codigo;
    int pedido;

    printf("Ingrese el código del pedido: ");
    scanf("%d", &codigo);

    while (codigo < 0 || codigo > 10) {
        printf("El código introducido no es válido. Vuelva a intentarlo: ");
        scanf("%d", &codigo);
    }

    while (codigo != 0) {
        printf("Ingrese la cantidad de pedidos deseados: ");
        scanf("%d", &pedido);

        listaPedidos[codigo] += pedido;

        printf("Vuelva a ingresar un código o 0 si desea terminar: ");
        scanf("%d", &codigo);

        while (codigo < 0 || codigo > 10) {
            printf("El código introducido no es válido. Vuelva a intentarlo: ");
            scanf("%d", &codigo);
        }
    }

    int i;

    printf("\n");
    for (i = 1; i <= 10; ++i) {
        printf("Código: %d - Unidades solicitadas: %d\n", i, listaPedidos[i]);
    }

    return 0;
}
