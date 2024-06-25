/* Ejercicio 1: Factorial de un Número

Objetivo:
Escribir un programa que calcule el factorial de un número ingresado por el usuario.

Requisitos:

    Usar una función LeerNumero para leer y validar que el número está en un rango válido (1 a 10).
    Usar una función CalcularFactorial para calcular el factorial del número. */

#include <stdio.h>

int LeerNumero (int limite_inferior, int limite_superior);
int CalcularFactorial(int numero);

int main() {

    int numero;
    int factorial;

    numero = LeerNumero(1, 10);
    factorial = CalcularFactorial(numero);

    if (numero < 1 || numero > 10) {
        return 1;
    } else {
        printf("El factorial de %d es %d\n", numero, factorial);
    }
    return 0;
}

int LeerNumero (int limite_inferior, int limite_superior) {
    int numero;

    do {
        printf("Ingrese un número entre %d y %d: ", limite_inferior, limite_superior);
        scanf("%d", &numero);

        if (numero < limite_inferior || numero > limite_superior) {
            printf("El número ingresado no es válido.\n");
            continue;
        }
        
        

    }   while (numero < limite_inferior || numero > limite_superior);

return numero;
}

int CalcularFactorial(int numero) {

    int factorial = 1;

    for (int i = 1; i <= numero; ++i) {
        factorial *= i;
    }

    return factorial;
}