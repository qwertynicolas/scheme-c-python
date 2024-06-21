/* Se ingresan 3 números enteros. Informarlos en orden creciente. */ 

#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b, c;

    printf("Ingresar el primer número: ");
    scanf("%d", &a);
    printf("Ingresar el segundo número: ");
    scanf("%d", &b);
    printf("Ingresar el tercer número: ");
    scanf("%d", &c);

    if (a > b && a > c && b > c) { // -_- esto es una álgebra de boole?
        printf("En orden creciente: %d, %d, %d.\n", c, b, a);
    } else if (b > a && b > c && c > a) {
        printf("En orden creciente: %d, %d, %d.\n", a, c, b);
    } else if (c > a && c > b && a > b) {
        printf("En orden creciente: %d, %d, %d.\n", b, a, c);
    } else if (a > b && a > c && c > b) {
        printf("En orden creciente: %d, %d, %d.\n", b, c, a);
    } else if (b > a && b > c && a > c) {
        printf("En orden creciente: %d, %d, %d.\n", c, a, b);
    } else if (c > b && c > a && b > a) {
        printf("En orden creciente: %d, %d, %d.\n", a, b, c);
    } 

    return 0;
}
