/* Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor -10, para ello generar una función
que valide dicho ingreso. Calcular:
a. Cuántos números son primos.
b. Cantidad de números pares.
c. Promedio de los números impares.
Utilizar las siguientes funciones:
• Resto: recibe por parámetro el Dividendo y el Divisor; Retorna el resto.
• EsPar: recibe por parámetro un número; Retorna 1 si es Par, 0 si es Impar; Invoca a la función Resto.
• EsPrimo: recibe por parámetro un número; Retorna 1 si es primo, 0 si no es primo; Invoca a la
función Resto. (un número es primero si solo es divisible por 1 y por sí mismo).
• Promedio: recibe por parámetro la suma y el contador; Retorna el promedio si contador > 0 sino
Retorna 0. */

#include <stdio.h>

int Resto (int dividendo, int divisor);
int EsPar (int num);
int EsPrimo (int num);
double Promedio (int suma, int contador);

int main() {

    int suma_impares = 0;
    int contador_impares = 0;
    int num;
    int pares = 0;
    int primos = 0;

    while (1) {

        printf("Ingrese números positivos entre 1 y 50 (-10 para finalizar): ");
        scanf("%d", &num);
        if (num == -10) {
            break;
        }

        if (num < 1 || num > 50) {
            printf("Número fuera de rango. Intente nuevamente.\n");
            continue;
        }


        if (EsPrimo(num)) { // 0 = falso. 1 = verdadero
            ++primos;
        }

        if (EsPar(num)) {
            ++pares;
        } else {
            ++contador_impares;
            suma_impares += num;
        }
    }   


    double promedio = Promedio(suma_impares, contador_impares);
    if (promedio > 0) {
        printf("Promedio de números impares: %.2f\n", promedio);
    } else {
        printf("No se ingresaron números impares.\n");
    }

    printf("Cantidad de números primos: %d\n", primos);
    printf("Cantidad de números pares: %d\n", pares);

    return 0;
}


int Resto(int dividendo, int divisor) {

    return dividendo % divisor;

}

int EsPrimo(int num) {

    if (num < 2) {
        return 0;
    }

    for (int i = 2; i * i <= num; ++i) { // se calcula la raíz cuadrada, es lo mismo que hacer i <= num / 2, pero más eficiente puesto que se reducen las iteraciones realizadas
        if (Resto(num, i) == 0) {
            return 0;
        }
    }

    return 1;

}

int EsPar(int num) {

    return Resto(num, 2) == 0; // si esto se cumple, la función regresa un 1, caso contrario regresa un 0

}

double Promedio(int suma, int contador) {

    if (contador > 0) {
        return (double)suma / contador;
    } else {
        return 0;
    }

}

