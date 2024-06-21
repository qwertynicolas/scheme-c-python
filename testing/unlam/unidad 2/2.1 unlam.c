/*2.1. Se ingresan la cantidad de horas trabajadas y el valor por hora de un empleado. Determinar el sueldo.*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int sueldo;
    int horas;
    int sueldo_promedio;

    printf("Ingrese las cantidad de horas trabajadas: ");
    scanf("%d", &horas);
    printf("Ingrese el valor por hora: ");
    scanf("%d", &sueldo);

    sueldo_promedio = horas * sueldo;

    printf("El sueldo mensual es: %d", sueldo_promedio);
    
    return 0;
}
