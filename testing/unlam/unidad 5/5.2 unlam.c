// Confeccionar un programa para calcular el valor de la siguiente suma: 100 + 95 + 90 + ... + 50.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int suma = 0;

    for (i = 100; i >= 50; --i) {
        if (i % 5 == 0) {
            suma += i;

        }
    } 

    printf("El valor de la suma es: %d\n", suma);

    return 0;
}
