#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i, nota, legajo;
    int aplazos, promociones;
    aplazos = promociones = 0;

    for (i = 0; i <= 20; ++i) {
        printf("Ingresar legajo y nota del alumno: ");
        scanf("%d %d", &legajo, &nota);

        if (nota < 4) {
            ++aplazos;
        }

        if (nota >= 7) {
            printf("El alumno con legajo %d ha promocionado.\n", legajo);
        }
    }

    printf("\nAlumnos aplazados: %d", aplazos);

    return 0;
}
