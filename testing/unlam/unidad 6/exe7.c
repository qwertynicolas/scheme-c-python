/* Ejercicio 4: Máximo y Mínimo de Números Ingresados

Objetivo:
Escribir un programa que determine el número máximo y el número mínimo de una serie de números ingresados por el usuario.

Requisitos:

    Usar una función LeerNumero para leer y validar que el número está en un rango válido (-1000 a 1000).
    Usar funciones EncontrarMaximo y EncontrarMinimo para determinar el máximo y mínimo de los números ingresados.
    El ingreso de datos termina cuando se ingresa el número 0. */

#include <stdio.h>
#include <limits.h>

int LeerNumero (int limite_inferior, int limite_superior);
int EncontrarMaximo(int numero, int maximo);
int EncontrarMinimo(int numero, int minimo);

int main() {

    int numero;
    int maximo = INT_MIN;
    int minimo = INT_MAX;

    while (1) {

    numero = LeerNumero(-1000, 1000);
    if (numero == 0) {
        break;
    }

    maximo = EncontrarMaximo(maximo, numero);
    minimo = EncontrarMinimo(minimo, numero);
    }
    
        if (maximo != INT_MIN && minimo != INT_MAX) {
        printf("El número máximo ingresado es: %d\n", maximo);
        printf("El número mínimo ingresado es: %d\n", minimo);
    } else {
        printf("No se ingresaron números.\n");


    }

    return 0;

}

int LeerNumero(int limite_inferior, int limite_superior) {
    
    int numero;

    do {

        printf("Ingrese un número entre %d y %d. 0 para finalizar: ", limite_inferior, limite_superior);
        scanf("%d", &numero);

        if (numero < limite_inferior || numero > limite_superior) {
            printf("El número ingresado no es válido. Intente nuevamente.\n");
            continue;
        }


    } while (numero < limite_inferior || numero > limite_superior);

    return numero;
}

int EncontrarMaximo (int maximo, int numero) {
    return (numero > maximo) ? numero : maximo;
}

int EncontrarMinimo(int minimo, int numero) {
    return (numero < minimo) ? numero : minimo;
}