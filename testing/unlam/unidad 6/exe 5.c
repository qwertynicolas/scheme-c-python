/* Ejercicio 2: Suma de los N Primeros Números Naturales

Objetivo:
Escribir un programa que calcule la suma de los primeros N números naturales.

Requisitos:

    Usar una función LeerNumero para leer y validar que el número está en un rango válido (1 a 100).
    Usar una función CalcularSuma para calcular la suma de los primeros N números naturales */

#include <stdio.h>

int LeerNumero (int limite_inferior, int limite_superior);
int CalcularSuma (int suma);

int main () {

    int numero;
    int suma;

    numero = LeerNumero(1, 100);
    suma = CalcularSuma(numero);

    printf("La suma de los primeros %d números naturales es %d\n", numero, suma);

    return 0;
}

int LeerNumero (int limite_inferior, int limite_superior) {
    int numero; 

    do {
        printf("Ingrese un número entre %d y %d: ", limite_inferior, limite_superior);
        scanf("%d", &numero);
        if (numero < limite_inferior || numero > limite_superior) {
            printf("El número ingresado no es válido. Intente nuevamente.\n");
            continue;
        }

    }   while (numero < limite_inferior || numero > limite_superior);

    return numero;
}

int CalcularSuma (int numero) {

int suma = 0;


    for (int i = 1; i <= numero; ++i) {
            suma += i;
        }
    
return suma;
}
