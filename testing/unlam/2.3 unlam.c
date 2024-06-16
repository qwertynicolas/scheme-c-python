/*Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con mensajes
aclaratorios la suma, el producto, el cociente y el resto.*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1;
    int n2;
    int suma;
    int producto;
    float cociente;
    int resto;

    printf("Ingrese el primer número entero: ");
    scanf("%d", &n1);
    printf("Ingrese el segundo número entero: ");
    scanf("%d", &n2);
    getchar();

    suma = n1 + n2;
    producto = n1 * n2;
    cociente = n1 / n2;
    resto = n1 % n2;

    printf("La suma entre los números es: %d\n", suma);
    printf("El producto entre los números es: %d\n", producto);
    printf("El cociente entre los números es: %.2f\n", cociente);
    printf("El resto entre los números es: %d\n", resto);

    return 0;
}