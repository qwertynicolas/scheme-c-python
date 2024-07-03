/* Se ingresan números enteros, hasta que se ingrese el número cero. Determinar los 2 valores mayores. */

#include <stdio.h>

int main () {

    int num;
    int mayor1 = -100;
    int mayor2 = -100;
    int contador = 0;

    while (1) {

        printf("Ingrese valores enteros (0 para finalizar): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        } else {
            ++contador;
        }

        if (num > mayor1) {
            mayor1 = num;
        }

        if (num > mayor2 && num < mayor1) {
            mayor2 = num;
        }

    }


    if (contador == 0) {
        printf("No se ingresaron valores válidos.\n");
    } else {
        printf("Los dos valores más grandes fueron: %d y %d\n", mayor1, mayor2);
    }

    return 0;
}