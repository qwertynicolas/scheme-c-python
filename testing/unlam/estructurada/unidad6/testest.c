#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Fecha;

typedef struct {
    long int DNI;
    char nombreCompleto[41];
    char sexo;
    Fecha nacimiento;
} Persona;

int main(void)
{
    Persona alumno;
    int i;
    FILE *pf;
    size_t len;

    pf = fopen("Alumno.dat", "wb");

    if (pf == NULL) {
        printf("Error al abrir.\n");
        getchar();
        exit(1);
    }

    for (i = 0; i < 10; i++) {
        printf("Ingrese el número de DNI: ");
        scanf("%ld", &alumno.DNI);
        getchar();

        printf("Ingrese nombre y apellido: ");
        fgets(alumno.nombreCompleto, 41, stdin);

        len = strlen(alumno.nombreCompleto);

        if (len > 0 && alumno.nombreCompleto[len-1] == '\n')
            alumno.nombreCompleto[len-1] = '\0';

        printf("Ingrese el género del alumno: ");
        scanf(" %c", &alumno.sexo);

        printf("Ingrese el día de nacimiento: ");
        scanf("%d", &alumno.nacimiento.day);
        printf("Ingrese mes de nacimiento: ");
        scanf("%d", &alumno.nacimiento.month);
        printf("Ingrese año de nacimiento: ");
        scanf("%d", &alumno.nacimiento.year);

        fwrite(&alumno, sizeof(Persona), 1, pf);
    }

    fclose(pf);

    return 0;
}
