/* Confeccionar un programa que permita ingresar varias ternas de valores a punto flotante, que finalice al
ingresar una terna con los valores ORDENADOS en forma creciente. Para cada terna exhibir la siguiente
pantalla:
** OPCIONES POSIBLES **
1 – Mayor valor
2 – Promedio
3 – Suma
4 - Finalizar
** Digite su opción:
Según la opción deseada debe aparecer en pantalla el resultado, sin borrar el menú. No admitir otros
valores de opción. Confeccionar y utilizar una función PARA CADA UNA de las opciones y otra para detectar
la condición final. */

#include <stdio.h>
#include <stdlib.h>
// funciona todo perfecto
int Menu (float num1, float num2, float num3); // una terna es un valor de 3 números
float MayorValor (float num1, float num2, float num3);
float Promedio (float num1, float num2, float num3);
float Suma (float num1, float num2, float num3); 
float Finalizar(float num1, float num2, float num3); // esta función debería de reiniciar todo el programa y permitirme volver a ingresar una terna (creo, pero no sé como hacerlo)
int CondicionFinal (float num1, float num2, float num3); // esto remplazaría a las líneas 37 y 38 en main

// según la consigna debería de usar una función para la opción 4, pero no le encuentro la forma

int main() {

    float num1, num2, num3;
    int opcion;
    float mayorValor;
    float promedio;
    float suma;

    printf("Ingrese una terna de valores (1 2 3 si desea finalizar): "); // me pide que termine cuando se ingrese una terna de valores ordenados en forma creciente, creo que se refiere a esto
    scanf("%f %f %f", &num1, &num2, &num3);

    if (CondicionFinal(num1, num2, num3)) { // esto está funcionando mal, y no tengo idea del porque. tenía que establecer dos valores para devolver, no solo un 1 (verdadero)
        return 0;
    } 
    

    while (1) {
        opcion = Menu(num1, num2, num3);

        switch (opcion) {
            case 1 : 
            mayorValor = MayorValor(num1, num2, num3); // funciona mal, el error estaba en que los valores de las variables estaban en int en vez de float
            printf("Número de mayor valor: %.2f", mayorValor);
            break;
            case 2 : 
            promedio = Promedio(num1, num2, num3); // funciona bien, sorprendentemente
            printf("Promedio: %.2f", promedio);
            break;
            case 3 :
            suma += Suma(num1, num2, num3);
            printf("Suma: %.2f", suma); // funciona mal, pasaba lo mismo que en la función de mayor valor
            break;
            case 4 :
            printf("Saliendo del programa...\n");
            printf("Ingrese una terna de valores (1 2 3 si desea finalizar): ");
            scanf("%f %f %f", &num1, &num2, &num3); // acá también iría la condicion final
            if (CondicionFinal(num1, num2, num3)) {
                return 0;
            } else {
                continue;
            }
            // era un continue, no un return 1

            // se podría hacer un if (opcion == 4) break; pero está teniendo el mismo resultado hacerlo dentro del switch 
        }

        printf("\nPresione Enter si desea continuar...\n");
        getchar();
        getchar();
        
    }

    return 0;
}

int Menu(float num1, float num2, float num3) {

    int opcion;

    do {

        printf("\n** OPCIONES POSIBLES **\n");
        printf("---------- -- ---------\n"); 
        printf("(1) Mayor valor\n");
        printf("(2) Promedio\n");
        printf("(3) Suma\n");
        printf("(4) Finalizar\n");
        printf("---------- -- ---------\n");
        printf("Digite su opción: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 4) {
            printf("No es una opción válida.\n");
        }


    }   while (opcion < 1 || opcion > 4);

    return opcion;
}

float MayorValor(float num1, float num2, float num3) {

    float mayor; // no hay necesidad de establecer esta variable, podría hacer un return num1, return num2 o return num3 directamente, sin necesidad de una variable extra

    if (num1 > num2 && num1 > num3) {
        mayor = num1;
    } else if (num2 > num1 && num2 > num3) {
        mayor = num2;
    } else if (num3 > num1 && num3 > num2) {
        mayor = num3;
    }

    return mayor;
}

float Suma(float num1, float num2, float num3) { // por alguna razón no funciona si no lo establezco de está manera, si intento que me devuelva el valor de suma sin antes establecer una variable no funciona
    float suma;
    suma = (float) num1 + num2 + num3;
    return suma;
}

float Promedio(float num1, float num2, float num3) {
    return (num1 + num2 + num3) / 3; // se podría utilizar la función de suma
}

int CondicionFinal(float num1, float num2, float num3) {

    if (num1 == 1 && num2 == 2 && num3 == 3) { // en teoría debería de ser cualquier par ordenado en forma creciente, pero el más conveniente es 1, 2 y 3, ya que si ingreso por ejemplo 3.46, 7.67 y 9.87 el programa finalizaría, y no creo que sea cómodo que ocurra eso
        return 1;
    } else {
        return 0;
    }
}

