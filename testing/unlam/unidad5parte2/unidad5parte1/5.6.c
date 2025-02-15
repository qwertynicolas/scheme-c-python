#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n1, n2, i;
    int sumaOrdenPar, suma3, suma5;
    sumaOrdenPar = suma3 = suma5 = 0;

    printf("¿Cuántos números desea ingresar? ");
    scanf("%d", &n1);

    for (i = 1; i <= n1; ++i) {
        printf("Ingrese el número Nº%d: ", i);
        scanf("%d", &n2);

        if (i % 2 == 0) {
            sumaOrdenPar += n2;
        }

        if (n2 % 5 == 0) {
            suma5 += n2;
        }

        if (n2 % 3 == 0) {
            suma3 += n2;
        }
    }

    printf("Sumatoria de valores múltiplos de 5: %d\n", suma5);
    printf("Sumatoria de valores múltiplos de 3: %d\n", suma3);
    printf("Sumatoria de valores ingresados en orden par: %d", sumaOrdenPar);

    return 0;
}
