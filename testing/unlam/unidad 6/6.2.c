/* Se ingresan números enteros comprendidos entre 100 y 2000 (usar función LeerYValidar). Determinar
usando la función EstaDentroDelRango:
a. Cantidad de números ingresados entre 100 y 500
b. Cantidad de números pares ingresados entre 500 y 1200
c. Promedio de números ingresados entre 1200 y 2000
El ingreso de datos finaliza cuando se ingresa un número igual a 99.
Para realizar este programa se deben realizar las siguientes funciones:
• EstaDentroDelRango: que reciba 3 enteros correspondientes a un número a validar y los límites
superior e inferior del rango. La función debe retornar un 1 si el número a validar se encuentra
dentro del rango indicado o un 0 si no lo está.
• LeerYValidar: que reciba los límites superior e inferior de un rango y retorne un número que se
encuentre dentro del mismo. (El ingreso de datos se realiza dentro de la función). Para validar el
rango utilizar la función EstaDentroDelRango realizada en el punto anterior.. */

#include <stdio.h>

int EstaDentroDelRango(int numero, int limite_inferior, int limite_superior);
int LeerYValidad(int limite_inferior, int limite_superior);

int main() { // pensar a futuro sobre para que voy a usar cierta función y el rol que está va a cumplir en el programa

    int numero;
    int entre100_500 = 0;
    int pares500_1200 = 0;
    int suma1200_2000 = 0;
    int entre1200_2000 = 0;

    while (1) {
        numero = LeerYValidad(100, 2000);
        if (numero == 99) {
            break;
        }

        // contar entre 100 y 500

        if (EstaDentroDelRango(numero, 100, 500)) {
            ++entre100_500;
        }
        if (EstaDentroDelRango(numero, 500, 1200) && (numero % 2 == 0)) {
            ++pares500_1200;
        }

        if (EstaDentroDelRango(numero, 1200, 2000)) {
            ++entre1200_2000;
            suma1200_2000 += numero;
        }
}

    printf("Cantidad de números ingresados entre 100 y 500: %d\n", entre100_500);
    printf("Cantidad de pares ingresados entre 500 y 1200: %d\n", pares500_1200);
    if (entre1200_2000 > 0) {
        printf("El promedio de números ingresados entre 1200 y 2000 es %.2f\n", (float)suma1200_2000 / entre100_500);
    } else {
        printf("No se ingresaron números entre 1200 y 2000.\n");
    }
    return 0;
}

int EstaDentroDelRango(int numero, int limite_inferior, int limite_superior) {
    return (numero >= limite_inferior && numero <= limite_superior) ? 1 : 0;
}

int LeerYValidad(int limite_inferior, int limite_superior) { // en el llamado a la funcion en main le asigno los valores 100 y 2000, que son los límites
    int numero;
    do {
        printf("Ingrese un número entre %d y %d o 99 si desea finalizar: ", limite_inferior, limite_superior);
        scanf("%d", &numero);
        if (numero == 99) {
            return 99;
        }

    } while(!EstaDentroDelRango(numero, limite_inferior, limite_superior)); // este bucle no termina hasta que devuelva 1, que es cuando numero toma un valor dentro del rango
    return numero;
    
}