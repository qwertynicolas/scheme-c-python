/* Ejercicio 1: Suma de Números Pares en un Rango

Escribe un programa que lea números enteros en un rango de 50 a 1000 (usa una función LeerYValidar). El programa debe:

    Contar cuántos números pares se ingresan.
    Calcular la suma de todos los números pares ingresados.
    Terminar cuando se ingrese el número 0. */

#include <stdio.h>
#include <stdlib.h>

int EstaDentroDelRango (int numero, int limite_inferior, int limite_superior);
int LeerYValidar (int limite_inferior, int limite_superior);

int main () {

    int numero;
    int esPar = 0;
    int sumaPares = 0;

    while (1) {
        numero = LeerYValidar(50, 1000);
        if (numero == 0){
        break;
    }

    if (numero % 2 == 0) {
        ++esPar;
        sumaPares += numero;
    }
}

printf("Cantidad de números pares: %d\n", esPar);
printf("Suma de todos los números pares: %d\n", sumaPares);

return 0;

}

int EstaDentroDelRango (int numero, int limite_inferior, int limite_superior) {
    return (numero >= limite_inferior && numero <= limite_superior) ? 1 : 0;
}

int LeerYValidar (int limite_inferior, int limite_superior) {
    int numero;
    do {
        printf("Ingrese un número entre %d y %d: ", limite_inferior, limite_superior);
        scanf("%d", &numero);
        if (numero == 0) {
            return 0;
        }

    } while (!EstaDentroDelRango(numero, limite_inferior, limite_superior));

    return numero;
} 