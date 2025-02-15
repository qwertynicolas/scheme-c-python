#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int dni, nota, i;
    int notaMayor = 0;
    int dniMayor = 0;

    for (i = 0; i < 10; ++i) {
        printf("Ingrese el DNI del alumno: ");
        scanf("%d", &dni);

        /* if (dni > dniMayor) { */
        /*     dniMayor = dni; */
        /* } */

        printf("Ingrese la nota promedio: ");
        scanf("%d", &nota);

        if (nota > notaMayor) {
            dniMayor = dni;
        }
    }

    printf("El DNI del alumno con la mayor nota es: %d", dniMayor);

    return 0;
}
