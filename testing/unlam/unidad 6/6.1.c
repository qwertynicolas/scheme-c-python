/* Realizar un programa que al ingresar solicite el ingreso de dos números enteros y luego muestre por
pantalla el siguiente menú (las xx de los números deben ser reemplazadas con los valores
correspondientes):
Menú de Opciones
---- -- --------
Numero 1: xx Numero 2: xx
1) Sumar
2) Restar
3) Multiplicar
4) Dividir
5) Ingresar Nuevos Números
6) Salir
Ingrese su opción:
Al ingresar el número de la opción del 1 al 4, se realiza la operación y muestra el resultado hasta que se
presione una tecla. Luego vuelve a mostrar el menú para poder realizar otra operación con los mismos
números. La opción 5 pide el ingreso de dos nuevos números de trabajo mientras que la opción 6 sale y
cierra el programa.
El ingreso de la opción debe estar validado y en caso de ingresarse un número no válido debe solicitarlo
nuevamente.
Usar una función para mostrar el menú y retornar el valor elegido. */


#include <stdio.h>
#include <stdlib.h>

int menu(int num1, int num2) { // acá se realiza el menú de opciones y la interfaz de texto que va a ver el usuario

    int opcion;
    do { // este bucle me asegura que el usuario eliga una opción válida
        printf("\nMenú de opciones\n");
        printf("------- -- -------\n");
        printf("Número 1: %d Número 2: %d\n", num1, num2);
        printf("1) Sumar\n");
        printf("2) Restar\n");
        printf("3) Multiplicar\n");
        printf("4) Dividir\n");
        printf("5) Ingresar nuevos números\n");
        printf("6) Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 6) {
            printf("La operación no es válida.\n");
        }
    } while (opcion < 1 || opcion > 6);

    return opcion; // esto me va a devolver el valor de opción al programa principal en main
}

int main(){ // acá le tengo que pedir al usuario el ingreso de los números

int num1, num2, opcion;
double resultado;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    while (1) { // bucle infinito que termina cuando se ingresa 6
    opcion = menu(num1, num2); // este llamado a la funcion menu me devuelve la opcion elegida

    // un switch case para manejar las opciones que elija el usuario

    switch (opcion) {
        case 1 :
        resultado = num1 + num2;
        printf("%d + %d = %.2f\n", num1, num2, resultado);
        break;
        case 2 :
        resultado = num1 - num2;
        printf("%d - %d = %.2f\n", num1, num2, resultado);
        break;
        case 3 :
        resultado = num1 * num2;
        printf("%d * %d = %.2f\n", num1, num2, resultado);
        break;
        case 4 : 
        if (num2 == 0) {
            printf("No se puede dividir por cero.\n");
        } else {
            resultado = (double)num1 / num2;
            printf("%d / %d = %.2f\n", num1, num2, resultado);
        }
        break;
        case 5 : 
        printf("Ingrese el primer número: ");
        scanf("%d", &num1);
        printf("Ingrese el segundo número: ");
        scanf("%d", &num2);
        break;

        case 6 : 
        printf ("Saliendo del programa...\n");
        return 0;
    }

    printf("Presione Enter si desea continuar...\n");
    getchar();
    getchar();

    }

    return 0;
}