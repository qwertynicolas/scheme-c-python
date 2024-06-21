/* Se ingresan DNI y la nota promedio de 10 alumnos. Determinar el DNI del alumno de mayor nota
promedio (considerar único). */

#include <stdio.h>
#include <stdlib.h>

int main () {

    int dni;
    float nota_promedio;
    const int alumnos = 10;
    int dniNotaMax;
    float NotaMax = 0.0;

    // pide unicidad por ende no se puede repetir el mismo dni (no tengo idea de cómo hacer esto)

    for (int i = 0; i < alumnos; ++i) {
        printf("Ingrese el D.N.I del alumno Nº%d: ", i + 1);
        scanf("%d", &dni);
        printf("Ingrese la nota promedio del alumno Nº%d: ", i + 1);
        scanf("%f", &nota_promedio);

        if (nota_promedio > NotaMax) {
            NotaMax += nota_promedio;
            dniNotaMax = dni;
        }
    }

    printf("El D.N.I del alumno con mayor nota es %d.\n", dniNotaMax);

    return 0;
}