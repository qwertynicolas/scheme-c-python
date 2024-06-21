
#include <stdio.h>
#include <math.h>

// Función para verificar si un número es primo
int esPrimo(int n) {
    if (n <= 1) {
        return 0; // Los números menores o iguales a 1 no son primos
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return 0; // Encontró un divisor, no es primo
        }
    }
    return 1; // No encontró divisores, es primo
}

int main() {
    int contador_primos = 0;

    printf("Números primos entre 1 y 100:\n");
    for (int i = 2; i <= 100; ++i) {
        if (esPrimo(i)) {
            printf("%d ", i);
            ++contador_primos;
        }
    }

    printf("\nCantidad de números primos encontrados: %d\n", contador_primos);

    return 0;
}
