/* Confeccionar un programa que permita ingresar la fecha actual (día, mes y año) y la fecha de nacimiento
de una persona (día, mes y año). Con ambos datos debe calcular la edad de dicha persona. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int dia_actual, mes_actual, anio_actual;
    int dia_nacimiento, mes_nacimiento, anio_nacimiento;
    int edad;

    printf("Ingrese la fecha actual (día mes año): ");
    scanf("%d %d %d", &dia_actual, &mes_actual, &anio_actual);
    printf("Ingrese su fecha de nacimiento (día mes año): "); //apretar enter luego de poner un número
    scanf("%d %d %d", &dia_nacimiento, &mes_nacimiento, &anio_nacimiento);

    edad = anio_actual - anio_nacimiento;

    if (mes_actual < mes_nacimiento || (mes_actual == mes_nacimiento && dia_actual < dia_nacimiento)) {
        edad--;
    }

    printf("Su edad actual es de %d años.\n", edad);

    return 0;
}