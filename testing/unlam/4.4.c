/* Ingresar 3 valores reales y:
a. Si los dos primeros son mayores al tercero informar “MAYORES AL TERCERO”.
b. Si los tres son iguales informar “TRES IGUALES .
c. Si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR”. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    double a, b ,c; 

    printf("Ingresar el primer número real: ");
    scanf("%lf", &a);
    printf("Ingresar el segundo número real: ");
    scanf("%lf", &b);
    printf("Ingresar el tercer número real: ");
    scanf("%lf" , &c);

    if (a > c && b > c) {
        printf("Los dos primeros son mayores al tercero.\n");
    } else if (a == b && a == c && b == c) {
        printf("Los tres son iguales.\n");
    } else if (a < c || b < c) {
        printf("Alguno de los dos primeros números es menor al tercero.\n");
    } else {
        printf("Nada que informar.\n");
    }

    return 0;
}
