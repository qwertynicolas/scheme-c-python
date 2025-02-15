#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int valorHora, horasTrabajadas;

    printf("Ingrese el valor por hora: ");
    scanf("%d", &valorHora);

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horasTrabajadas);

    int sueldo = valorHora * horasTrabajadas;

    if (horasTrabajadas > 50 && horasTrabajadas < 150) {
        sueldo += 500;
    } else if (horasTrabajadas > 150) {
        sueldo += 1500;
    }

    printf("El sueldo es de: %d", sueldo);

    return 0;
}
