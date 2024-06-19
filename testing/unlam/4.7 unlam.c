/* Confeccionar un programa que solicite e ingrese 3 valores reales positivos, mayores que cero y determine
e informe si forman o no triángulo. Para ello utilizar el teorema de la desigualdad del triángulo que establece
que la suma de las longitudes de cualesquiera de dos lados de un triángulo es mayor que la longitud del
tercer lado. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    double a, b, c;

    printf("Ingrese el primer valor real mayor que cero: ");
    scanf("%lf", &a);
    printf("Ingrese el segundo valor real mayor que cero: ");
    scanf("%lf", &b);
    printf("Ingrese el tercer valor real mayor que cero: ");
    scanf("%lf", &c);

     if (a > 0 && b > 0 && c > 0) {
        if (a + b > c && b + c > a && c + a > b) {
            printf("Los números forman un triángulo.\n");
        } else {
            printf("Los números NO forman un triángulo.\n");
        }
    } else {
        printf("Los números deben ser reales positivos mayores que cero.\n");
    }
    
    return 0;
}