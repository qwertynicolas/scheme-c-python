/* Confeccionar un programa que calcule e informe los valores de las potencias de 2 cuyo resultado sean
menores que 600. (1 2 4 8 16 …) */

// en esta unidad solo voy a usar while y do while en vez de for

#include <stdio.h>
#include <stdlib.h>

int main() {

    int potencia = 1;
    int num = 1;

    while (num < 600) {
        printf("%d ", num);
        potencia *= 2;
        num = potencia;
        }

    return 0;
}