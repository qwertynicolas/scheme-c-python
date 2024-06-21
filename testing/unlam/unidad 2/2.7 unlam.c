/*Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1;
    int decena;
    int centena;

    printf("Ingrese un número entero de 3 cifras: ");
    scanf("%d", &n1);

    decena = n1 / 10;
    centena = n1 / 100;

    printf("Descomposición en unidad: %d unidades\n", n1);
    printf("Descomposición en decena: %d decenas\n", decena);
    printf("Descomposición en centena: %d centenas\n", centena);

    return 0;

}
