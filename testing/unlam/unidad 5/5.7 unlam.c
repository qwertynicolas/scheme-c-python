/* Dadas 20 notas y legajos de alumnos de un curso. Determinar:
a. Cantidad de alumnos aplazados.
b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha Promocionado”. */

#include <stdio.h>
#include <stdlib.h>

int main() { // estás una hora poniendo las notas y los legajos, a quién se le ocurre hacer ejercicios así

    int nota_alumno;
    int notas = 20;
    int aplazos = 0;
    int legajo;

    for (int i = 0; i < notas; ++i) {
        printf("Ingrese el legajo del alumno Nº%d: ", i + 1); // faltaría una parte que verifique si el legajo se repite, pero no lo sé hacer (yet)
        scanf("%d", &legajo);
        printf("Ingrese la nota del alumno Nº%d: ", i + 1);
        scanf("%d", &nota_alumno);

    if (nota_alumno <= 0 || nota_alumno > 10) {
        printf("La nota no es válida.\n");
        i--;
        continue;
    }

    if (nota_alumno < 4) {
        ++aplazos;
    }

    if (nota_alumno >= 7) {
        printf("El alumno con legajo %d ha promocionado.\n", legajo);
    } 

    }

    printf("Hubo %d alumnos aplazados.\n", aplazos);

    return 0;
}