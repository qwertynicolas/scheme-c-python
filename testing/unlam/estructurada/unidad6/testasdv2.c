#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    int dni;
    char nombreCompleto[41];
    char sexo;
    Fecha nacimiento;
} Persona;

void mostrarDatos(Persona []);

int main(void)
{
    Persona alumnos[5];
    int i;
    FILE *pf;

    pf = fopen("DatosAlumnos.dat", "rb");

    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        fread(&alumnos[i], sizeof(Persona), 1, pf);
    }

    mostrarDatos(alumnos);
    fclose(pf);

    return 0;
}

void mostrarDatos(Persona alumnos[])
{
    int i;
    for (i = 0; i < 5; i++) {
        printf("Nombre del alumno Nº%d: %s\n", i+1, alumnos[i].nombreCompleto);
    }
}
