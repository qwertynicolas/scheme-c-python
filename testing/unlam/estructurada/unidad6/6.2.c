#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nota1;
    int nota2;
    float promedio;
} Notas;

typedef struct {
    int dni;
    char nombreCompleto[81];
    Notas nota;
} Alumno;

void mostrarContenido(char []);

int main(void)
{
    FILE *pf, *promocionados, *cursados, *reprobados;
    Alumno alumnos;

    pf = fopen("ALUMNOS.dat", "rb");
    promocionados = fopen("PROMOCIONADOS.dat", "wb");
    cursados = fopen("CURSADOS.dat", "wb");
    reprobados = fopen("REPROBADOS.dat", "wb");

    if (pf == NULL) {
        printf("Error al abrir el archivo de alumnos.\n");
        getchar();
        exit(1);
    }

    if (promocionados == NULL) {
        printf("Error al abrir el archivo de promocionados.\n");
        getchar();
        exit(1);
    }

    if (cursados == NULL) {
        printf("Error al abrir el archivo de cursados.\n");
        getchar();
        exit(1);
    }

    if (reprobados == NULL) {
        printf("Error al abrir el archivo de reprobados.\n");
        getchar();
        exit(1);
    }

    int i = 0;
    fread(&alumnos, sizeof(Alumno), 1, pf);
    while (!feof(pf)) {

        if (alumnos.nota.nota1 >= 7 && alumnos.nota.nota2 >= 7) {
            fwrite(&alumnos, sizeof(Alumno), 1, promocionados);
        } else if (alumnos.nota.nota1 >= 4 && alumnos.nota.nota2 >= 4) {
            fwrite(&alumnos, sizeof(Alumno), 1, cursados);
        } else {
            fwrite(&alumnos, sizeof(Alumno), 1, reprobados);
        }

        i++;
        fread(&alumnos, sizeof(Alumno), 1, pf);
    }

    fclose(pf);
    fclose(promocionados);
    fclose(cursados);
    fclose(reprobados);

    printf("Alumnos promocionados:\n");
    mostrarContenido("PROMOCIONADOS.dat");

    printf("Alumnos cursados:\n");
    mostrarContenido("CURSADOS.dat");

    printf("Alumnos reprobados:\n");
    mostrarContenido("REPROBADOS.dat");

    return 0;
}

void mostrarContenido(char nombreArchivo[])
{
    FILE *pf;
    Alumno alumnos;
    int i;

    pf = fopen(nombreArchivo, "rb");

    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    i = 0;
    fread(&alumnos, sizeof(Alumno), 1, pf);

    while (!feof(pf)) {
        printf("Nombre: %-s. Promedio: %.2f\n", alumnos.nombreCompleto, alumnos.nota.promedio);

        i++;
        fread(&alumnos, sizeof(Alumno), 1, pf);
    }

    fclose(pf);
}
