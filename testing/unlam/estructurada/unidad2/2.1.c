#include <stdio.h>

int main (void)
{
    int matriz[3][3], num;
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Ingrese el valor para la posición %d|%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Ingrese la constante para multiplicar la matriz: ");
    scanf("%d", &num);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] *= num;
        }
    }

    printf("Matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%02d ", matriz[i][j]);
        }

        printf("\n");
    }

    return 0;
}
