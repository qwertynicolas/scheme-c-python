/* Escribir un programa que solicite el año y el número de mes y nos informe cuantos días tiene dicho mes.
Debemos considerar que el año puede ser bisiesto. Un año es bisiesto cuando es divisible por 4 y no por
100 o el año es divisible por 400. */

#include <stdio.h>
#include <stdlib.h>


int main() {

    int anio, mes;

    printf("Ingrese el año: ");
    scanf("%d", &anio);
    printf("Ingrese el número del mes: ");
    scanf("%d", &mes);

    if (anio % 4 == 0) {
        if (mes == 1) {
            printf ("El mes tiene 31 días.\n"); 
        } else if (mes == 2) {
            printf("El mes tiene 29 días.\n");
        } else if (mes == 3) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 4) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 5) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 6) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 7) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 8) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 9) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 10) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 11) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 12) {
            printf("El mes tiene 31 días.\n");
        } else {
            printf("Número de mes no válido.\n");
        }
    } else if (anio % 4 != 0) {
        if (mes == 1) {
        printf ("El mes tiene 31 días.\n"); 
        } else if (mes == 2) {
            printf("El mes tiene 28 días.\n");
        } else if (mes == 3) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 4) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 5) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 6) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 7) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 8) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 9) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 10) {
            printf("El mes tiene 31 días.\n");
        } else if (mes == 11) {
            printf("El mes tiene 30 días.\n");
        } else if (mes == 12) {
            printf("El mes tiene 31 días.\n");
        } else {
            printf("Número de mes no válido.\n");
        }
    }
    return 0;
}
