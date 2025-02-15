#include <stdio.h>

float average (int x, int y)
{
    return (x + y) / 2;
}

int main (void)
{
    int dni, p1, p2;
    float promedio = 0.0;
    int loop = 1;

    while (loop) {
        printf("Ingrese el DNI del estudiante (-1 para finalizar): ");
        scanf("%d", &dni);

        if (dni < 0) {
            loop = 0;
        } else {
            printf("Ingrese las notas de los parciales: ");
            scanf("%d %d", &p1, &p2);

            if (p1 <= 0 || p1 > 10 || p2 <= 0 || p2 > 10) {
                printf("La nota no es válida. Intente nuevamente: "); // de esta forma solo valida una vez, para que valide hasta que ingrese un valor válido necesitaría hacer uso de un ciclo while
                scanf("%d %d", &p1, &p2);
            } else if (p1 >= 7 && p2 >= 7) {
                promedio += average(p1, p2);
                printf("El alumno con DNI: %d, obtuvo las notas %d y %d [PROMOCIONA]\n", dni, p1, p2);
            } else if (p1 < 4 || p2 < 4) {
                printf("El alumno con DNI: %d, obtuvo las notas %d y %d [REPROBO LA MATERIA]\n", dni, p1, p2);
            } else {
                printf("El alumno con DNI: %d, obtuvo las notas %d y %d [RINDE EXAMEN FINAL]\n", dni, p1, p2);
            }
        }
    }

    printf("Promedio de alumnos promocionados: %.2f", promedio);

    return 0;
}
