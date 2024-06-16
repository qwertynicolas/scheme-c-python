/*2.2. Se ingresan las notas de dos evaluaciones de un alumno. Determinar la nota promedio*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int nota1;
    int nota2;
    float notaPromedio;

    printf("Ingrese la nota de su primera evaluación: ");
    scanf("%d", &nota1);
    printf("Ingrese la nota de su segunda evaluación: ");
    scanf("%d", &nota2);

    notaPromedio = (nota1 + nota2) / 2;
    printf("Su nota promedio es: %1.2f", notaPromedio);
    return 0;
}