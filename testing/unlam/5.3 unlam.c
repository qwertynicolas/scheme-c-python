//Se ingresan 50 números enteros. Determinar el promedio de los números pares.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int numeros[50];
    int suma_pares = 0;
    int contador_pares = 0;
    int numero;

    for (int i = 0; i < 50; ++i) {
        printf("Ingrese un número entero (%d de 50): ", i + 1);
        scanf("%d", &numero);
        numeros[i] = numero;

        if (numero % 2 == 0) {
            suma_pares += numero;
            ++contador_pares;
        }
    }

    if (contador_pares > 0) {
        float promedio = (float)suma_pares / contador_pares;
        printf("El promedio de los números pares es %.2f\n", promedio);
    } else {
        printf("No se ingresaron números pares.\n");
    }

    return 0;
} 