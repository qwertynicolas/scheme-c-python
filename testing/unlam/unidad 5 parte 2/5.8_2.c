#include <stdio.h>
#include <math.h> // Necesario para usar sqrt()

int main() {
    int num, primosEncontrados = 0;
    int candidato = 2; // Empezamos desde el primer número primo

    printf("Ingrese la cantidad de primos que quiere calcular: ");
    scanf("%d", &num);

    while (primosEncontrados < num) {
        int esPrimo = 1; // Suponemos que el número es primo al principio

        // Verificar si candidato es primo
        for (int divisor = 2; divisor <= sqrt(candidato); divisor++) {
            if (candidato % divisor == 0) {
                esPrimo = 0; // No es primo, encontramos un divisor
                break;
            }
        }

        // Si es primo, lo mostramos
        if (esPrimo) {
            printf("%d-", candidato);
            primosEncontrados++;
        }

        candidato++; // primosamos al siguiente número para verificar si es primo
    }

    printf("\n");

    return 0;
}

