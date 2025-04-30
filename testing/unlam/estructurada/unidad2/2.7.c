#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRODUCTOS 20
#define TESTING 1

int search(int v[], int element, int size)
{
    int i = 0, pos = -1;

    while (pos == -1 && i < size) {
        if (v[i] == element) {
            pos = i;
        } else {
            i++;
        }
    }

    return pos;
}

void mostrarListado(float precio[], int codigos[])
{
    int i;

    for (i = 0; i < PRODUCTOS; i++) {
        printf("Código de producto: %d  Precio c/u: $%.2f\n", codigos[i], precio[i]);
    }
}

int main(void)
{
    srand((unsigned) time(NULL));

    int i, j;
    float precio[PRODUCTOS] = {0.0};
    int codigos[PRODUCTOS] = {0};

    if (TESTING) {
        printf("Running in test mode...\n");

        for (i = 0; i < PRODUCTOS; i++) {
            codigos[i] = 100 + rand() % 900;
            precio[i] = 1.0 + (rand() % 10000) / 100.0;
            printf("Producto %d: Código %d, Precio %.2f\n", i + 1, codigos[i], precio[i]);
        }
    } else {
        for (i = 0; i < PRODUCTOS; i++) {
            printf("Ingrese el código (100 a 999) y precio unitario del producto Nº%d: ", i + 1);
            scanf("%d %f", &codigos[i], &precio[i]);

            while (precio[i] <= 0.0) {
                printf("Precio no válido. Ingrese valores correctos: ");
                scanf("%d %f", &codigos[i], &precio[i]);
            }

            while ((codigos[i] < 100 || codigos[i] > 999) || (search(codigos, codigos[i], i)) != -1) {
                printf("Código no válido o repetido. Ingrese valores correctos: ");
                scanf("%d %f", &codigos[i], &precio[i]);
            }
        }
    }

    mostrarListado(precio, codigos);

    int unidadesVendidas[PRODUCTOS][12] = {{0}};
    float recaudacion[PRODUCTOS] = {0.0};
    float recaudacionMensual[12] = {0.0};// en base a código y mes
    // trimestres: 1 - 3, 3 - 6, 6 - 9, 9 - 12
    // 0-index based: 0 - 2, 2 - 5, 5 - 8, 8 - 11
    int dia, mes, codigo, cantidad;
    int productoCodigo;

    if (TESTING) {
        for (i = 0; i < 100; i++) { //  100 random sales
            codigo = codigos[rand() % PRODUCTOS];
            dia = 1 + rand() % 31;                // (1-31)
            mes = 1 + rand() % 12;                // (1-12)
            cantidad = 1 + rand() % 20;           // (1-20)

            productoCodigo = search(codigos, codigo, PRODUCTOS);
            unidadesVendidas[productoCodigo][mes - 1] += cantidad;
            recaudacion[productoCodigo] += (float)cantidad * precio[productoCodigo];
            recaudacionMensual[mes - 1] += (float)cantidad * precio[productoCodigo];
        }
    } else {
        printf("Ingrese el código del producto: ");
        scanf("%d", &codigo);

        while (codigo != 0) {
            while (search(codigos, codigo, PRODUCTOS) == -1) {
                printf("El código no es válido. Intente nuevamente: ");
                scanf("%d", &codigo);
            }

            printf("Ingrese el día de la venta: ");
            scanf("%d", &dia);

            while (dia < 1 || dia > 31) {
                printf("El día no es válido. Intente nuevamente: ");
                scanf("%d", &dia);
            }

            printf("Ingrese el mes de la venta: ");
            scanf("%d", &mes);

            while (mes < 1 || mes > 12) {
                printf("El mes no es válido. Intente nuevamente: ");
                scanf("%d", &mes);
            }

            productoCodigo = search(codigos, codigo, PRODUCTOS);

            printf("Ingrese la cantidad de unidades vendidas: ");
            scanf("%d", &cantidad);

            while (cantidad <= 0) {
                printf("La cantidad no es válida. Intente nuevamente: ");
                scanf("%d", &cantidad);
            }

            unidadesVendidas[productoCodigo][mes - 1] += cantidad;
            recaudacion[productoCodigo] += (float)cantidad * precio[productoCodigo];
            recaudacionMensual[mes - 1] += (float)cantidad * precio[productoCodigo];

            printf("Ingrese un nuevo código de producto o 0 si desea finalizar: ");
            scanf("%d", &codigo);
        }
    }

    for (i = 0; i < PRODUCTOS; i++) {
        for (j = 0; j < 12; j++) {
            printf("Producto: %d. Mes: %d. Cantidad vendida: %d.\n", i+1, j+1, unidadesVendidas[i][j]);
        }
    }

    printf("\n");

    float mayorRecaudacion = 0.0;
    int indexMayor;

    for (i = 0; i < PRODUCTOS; i++) {
        if (recaudacion[i] > mayorRecaudacion) {
            mayorRecaudacion = recaudacion[i];
            indexMayor = i;
        }
    }

    printf("Producto con mayor recaudación: Nº%d. Recaudación: %.2f\n", indexMayor+1, mayorRecaudacion);

    int trimestreMenor = 1;
    float menorRecaudacion = recaudacionMensual[0] + recaudacionMensual[1] + recaudacionMensual[2]; // suponemos que el primer trimestre es el de menor recaudacion
    int trimestre;
    float recaudacionTrimestre;

    for (trimestre = 1; trimestre < 4; trimestre++) {
        recaudacionTrimestre = 0.0;
        for (mes = trimestre * 3; mes < (trimestre + 1) * 3; mes++) {
            recaudacionTrimestre += recaudacionMensual[mes];
        }

        if (recaudacionTrimestre < menorRecaudacion) {
            trimestreMenor = 1 + trimestre;
            menorRecaudacion = recaudacionTrimestre;
        }
    }

    printf("Trimestre de menor recaudacion: Nº%d. Recaudacion: %.2f\n", trimestreMenor, menorRecaudacion);

    return 0;
}
