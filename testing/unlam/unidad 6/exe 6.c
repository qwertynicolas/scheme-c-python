/* Ejercicio 3: Promedio de Números Ingresados

Objetivo:
Escribir un programa que calcule el promedio de una serie de números ingresados por el usuario.

Requisitos:

    Usar una función LeerNumero para leer y validar que el número está en un rango válido (0 a 1000).
    Usar una función CalcularPromedio para calcular el promedio de los números ingresados.
    El ingreso de datos termina cuando se ingresa el número 0. */

#include <stdio.h>

int LeerNumero(int limite_inferior, int limite_superior);
double CalcularPromedio(int suma, int cantidad);

int main() {

    int numero;
    int cantidad = 0;
    int suma = 0;

    while (1) {
        numero = LeerNumero (0, 1000);
        if (numero == 0) {
            break;
        }

        suma += numero;
        ++cantidad;
    }

    if (cantidad > 0) {
        double promedio = CalcularPromedio(suma, cantidad);
        printf("El promedio de los números ingresados es de %.2f\n", promedio);
        printf("Se ingresaron %d números.\n", cantidad);
    } else {
        printf("No se ingresaron números.\n");
    }

    return 0;
}


double CalcularPromedio(int suma, int cantidad) {
    return (double)suma / cantidad;
}

int LeerNumero (int limite_inferior, int limite_superior) {

    int numero;

    do {

        printf("Ingrese un numero entre %d y %d. 0 para finalizar: ", limite_inferior, limite_superior);
        scanf("%d", &numero);

        if (numero < limite_inferior || numero > limite_superior) {
            printf("El número ingresado no es válido. Intente nuevamente.\n");
            continue;
        }

    }   while (numero < limite_inferior || numero > limite_superior);


    return numero;
}