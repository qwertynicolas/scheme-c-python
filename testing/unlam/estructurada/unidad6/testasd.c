#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void cargarDatos (Persona []);

int main(void)
{
    FILE *pf;
    Persona alumnos[5];
    int i;

    cargarDatos(alumnos);

    pf = fopen("DatosAlumnos.dat", "wb");
    if (pf == NULL) {
        printf("Error al abrir archivo.\n");
        getchar();
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        fwrite(&alumnos[i], sizeof(Persona), 1, pf);
    }
    fclose(pf);

    return 0;
}

void cargarDatos(Persona alumnos[])
{
    int i;
    size_t len;

    for (i = 0; i < 5; i++) {
        printf("Ingrese DNI: ");
        scanf("%d", &alumnos[i].dni);
        getchar();

        printf("Ingrese nombre y apellido: ");
        fgets(alumnos[i].nombreCompleto, 41, stdin);
        len = strlen(alumnos[i].nombreCompleto);

        if (len > 0 && alumnos[i].nombreCompleto[len-1] == '\n')
            alumnos[i].nombreCompleto[len-1] = '\0';

        printf("Ingrese el sexo: ");
        scanf(" %c", &alumnos[i].sexo);

        getchar();
        printf("Ingrese fecha de nacimiento: ");
        scanf("%d%d%d", &alumnos[i].nacimiento.dia, &alumnos[i].nacimiento.mes, &alumnos[i].nacimiento.anio);
    }
}
