/* Ingresar el valor de la hora y la cantidad de horas trabajadas por un empleado. Calcular su sueldo tomando
en cuenta que recibe un premio de $500 si trabajo más de 50 horas y, además, si trabajó más de 150 horas
se le otorgan $1000 adicionales. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int valor_hora, horas;
    double sueldo;

    printf("Ingrese el valor por hora: ");
    scanf("%d", &valor_hora);
    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horas);

    sueldo = valor_hora * horas;

    if (horas > 150) {
        sueldo += 1500;  
    } else if (horas > 50) {
        sueldo += 500;   
    }

    printf("Su sueldo es: $%.2f\n", sueldo);
    return 0;
}