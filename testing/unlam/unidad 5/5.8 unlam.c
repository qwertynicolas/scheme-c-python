/* Dadas las edades y estaturas de 45 alumnos de un curso. Determinar:
a. Edad promedio.
b. Estatura promedio.
c. Cantidad de alumnos mayores de 10 años.
d. Cantidad de alumnos que miden menos de 1.40 cm */

#include <stdio.h>
#include <stdlib.h>

int main() { // no sé si está bien o no el programa, no lo termine de correr en la terminal, es muy largo, again, who got this idea? 

    int edad;
    int suma_edad = 0;
    float altura;
    float suma_altura = 0;
    int mayores10 = 0;
    int menores140 = 0;
    int alumnos = 45;

    for (int i = 0; i < alumnos; ++i) {
        printf("Ingrese la edad del alumno Nº%d: ", i + 1);
        scanf("%d", &edad);
        printf("Ingrese la altura del alumno Nº%d: ", i + 1);
        scanf("%f", &altura);

        if (edad <= 0 || edad > 99) {
            printf("La edad no es valida.\n");
            --i;
            continue;
        } 

        suma_altura += altura;
        suma_edad += edad;

        if (edad > 10) {
            ++mayores10;
        }

        if (altura < 1.40) {
            ++menores140;
        }

    }

    float edad_promedio = (float)suma_edad / alumnos;
    float altura_promedio = suma_altura / alumnos;

    printf("La edad promedio de los alumnos es %.2f.\n", edad_promedio);
    printf("La altura promedio de los alumnos es %.2f.\n", altura_promedio);
    printf("Los alumnos mayores de 10 años son %d.\n", mayores10);
    printf("Los alumnos que miden menos de 1.40m son %d.\n", menores140);

    return 0;
}