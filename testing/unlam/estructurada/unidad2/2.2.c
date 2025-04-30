#include <stdio.h>
#define COL 4

void sumaFilas (int vector[], int matriz[][COL], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            vector[i] += matriz[i][j];
        }
    }
}

void sumaColumnas (int vector[], int matriz[][COL], int filas, int columnas)
{
    int i, j;

    for (j = 0; j < columnas; j++) {
        for (i = 0; i < filas; i++) {
            vector[j] += matriz[i][j];
        }
    }
}

void showMatrix(int matriz[][COL], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
}

void showVector(int vector[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
}

int main(void)
{
    int vectorFilas[5] = {0}, vectorColumnas[4] = {0}, matriz[5][4];

    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("Ingrese el valor %d|%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    sumaFilas(vectorFilas, matriz, 5, 4);

    printf("Vector fila:\n");
    showVector(vectorFilas, 5);
    printf("\n");

    sumaColumnas(vectorColumnas, matriz, 5, 4);

    printf("Vector columna:\n");
    showVector(vectorColumnas, 4);
    printf("\n");

    return 0;
}
