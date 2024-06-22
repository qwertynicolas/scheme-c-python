/* De cada uno de los alumnos de un curso se ingresa su número de DNI y las notas de los dos exámenes
parciales confeccionar, un programa que muestre por cada alumno su condición final con el siguiente
mensaje:
“El alumno con DNI: xxxxxxx, obtuvo las notas: xx y xx [condición final]”
La condición final se establece según las siguientes reglas:
• PROMOCIONA: ambas notas > = 7
• RINDE EXAMEN FINAL: ambas notas > = 4
• REPROBO LA MATERIA: alguna nota no cumple lo anterior
El programa finaliza cuando se ingresa un valor negativo como número de DNI. Al finalizar mostrar la nota
promedio de alumnos promocionados. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int dni, nota1, nota2;
    double nota_promedio = 0;
    double nota_promocion = 0;
    int num_promocionados = 0;

    // se rompe al ingresar un valor negativo como dni, osea cuando dni < 0
    // no especifica cuantos alumnos hay o cuanto es el maximo, por ende puede ser 1 solo alumno o 100 alumnos

    while (1) {
        printf("Ingrese el número de D.N.I del alumno: ");
        scanf("%d", &dni);
        if (dni < 0) {
            break;
        }

        printf("Ingrese la nota del primer exámen: ");
        scanf("%d", &nota1);
        printf("Ingrese la nota del segundo exámen: ");
        scanf("%d", &nota2);

        if (nota1 >= 7 && nota2 >= 7) {
            printf("El alumno con D.N.I %d, obtuvo las notas: %d y %d. PROMOCIONA.\n", dni, nota1, nota2);
            nota_promocion += (nota1 + nota2) / 2.0;
            ++num_promocionados;
        } else if (nota1 >= 4 && nota1 < 7 || nota2 >= 4 && nota2 < 7) {
            printf("El alumno con D.N.I %d, obtuvo las notas %d y %d. RINDE EXÁMEN FINAL.\n", dni, nota1, nota2);
        } else if (nota1 < 4 || nota2 < 4) {
            printf("El alumno con D.N.I %d, obtuvo las notas %d y %d. REPROBO LA MATERIA.\n", dni, nota1, nota2);
        } else {
            printf("La nota no es válida.\n");
            continue;
        }
    }

    if (num_promocionados > 0) {
        nota_promedio += nota_promocion / num_promocionados;
        printf("Nota promedio de alumnos promocionados: %.2f\n", nota_promedio);
    } else {
        printf("No hubo alumnos promocionados.\n");
    }

    return 0;
}