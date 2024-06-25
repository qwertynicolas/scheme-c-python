/* Ejercicio 2: Promedio de Números Negativos

Escribe un programa que lea números enteros (usa una función LeerYValidar que asegure que los números están entre -500 y 500). El programa debe:

    Contar cuántos números negativos se ingresan.
    Calcular el promedio de todos los números negativos ingresados.
    Terminar cuando se ingrese el número -1. */

#include <stdio.h>
#include <stdlib.h>

int LeerYValidar (int limite_inferior, int limite_superior); // -500 y 500
int EstaDentroDelRango (int numero, int limite_inferior, int limite_superior);

int main() {

    int numero;
    int cantNegativos = 0;
    double promedioNegativos;
    int sumaNegativos = 0;

    while (1) {
        numero = LeerYValidar(-500, 500);
        if (numero == -1) {
            break;
        }

        if (numero < 0) {
            ++cantNegativos;
            sumaNegativos += numero;  
        } 
    }

    if (cantNegativos > 0) {
        promedioNegativos = (double)sumaNegativos / cantNegativos;
        printf("Hubo %d números negativos.\n", cantNegativos);
        printf("El promedio de números fue de %.2f\n", promedioNegativos);
    } else {
        printf("No se ingresaron números negativos.\n");
    }

    return 0;
}

int LeerYValidar (int limite_inferior, int limite_superior) {
    int numero;

    do {

        printf("Ingrese un número entre %d y %d: ", limite_inferior, limite_superior);
        scanf("%d", &numero);
        if (numero == -1) {
            return -1;
        } 

    } while (!EstaDentroDelRango(numero, limite_inferior, limite_superior));

    return numero;
}

int EstaDentroDelRango (int numero, int limite_inferior, int limite_superior) {
    return (numero >= limite_inferior && numero <= limite_superior) ? 1 : 0;
}