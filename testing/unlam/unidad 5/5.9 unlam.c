/* Confeccionar un programa que exhiba por pantalla una lista, a dos columnas, con los primeros 15 números
impares en la primera y los 15 primeros pares en la segunda, incluyendo los títulos. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int impar = 1;
    int par = 2;
    int maximo = 15;

    printf("%-10s %-10s\n", "Impares", "Pares");

    for (int i = 0; i < maximo; ++i) {
    printf("%-10d %-10d\n", impar, par);
    
    par += 2;
    impar += 2;

    }

    return 0;
}