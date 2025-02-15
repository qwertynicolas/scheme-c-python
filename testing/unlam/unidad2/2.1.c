#include <stdio.h>
#include <stdlib.h>

int main()
{
    int horas_trabajadas, valor_hora;

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horas_trabajadas);
    printf("Ingrese el valor por hora: ");
    scanf("%d", &valor_hora);

    printf("El sueldo es de: %d\n", valor_hora * horas_trabajadas);

    return 0;
}
