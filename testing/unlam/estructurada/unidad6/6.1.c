#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void lectura();

int main(void)
{
    FILE *pf;
    int i = 0;
    Alumno alumnos[20];
    size_t len;

    pf = fopen("ALUMNOS.dat", "wb");
    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    int dniTemp;
    printf("Ingrese DNI o 0 para finalizar: ");
    do {
        scanf("%d", &dniTemp);
        if (dniTemp < 0) {
            printf("El valor ingresado no es válido. Intente nuevamente: ");
            scanf("%d", &dniTemp);
        }
    } while (dniTemp < 0);

    while (dniTemp != 0 && i < 20) {
        getchar();
        alumnos[i].dni = dniTemp;
        printf("Ingrese el nombre completo: ");
        fgets(alumnos[i].nombreCompleto, 81, stdin);

        len = strlen(alumnos[i].nombreCompleto);
        if (len > 0 && alumnos[i].nombreCompleto[len-1] == '\n')
            alumnos[i].nombreCompleto[len-1] = '\0';

        printf("Ingrese las notas de los parciales: ");
        do {
            scanf("%d %d", &alumnos[i].nota.nota1, &alumnos[i].nota.nota2);

            if (alumnos[i].nota.nota1 <= 0 || alumnos[i].nota.nota1 > 10) {
                printf("La nota del primer parcial no es válida. Intente nuevamente: ");
                scanf("%d", &alumnos[i].nota.nota1);
            }

            if (alumnos[i].nota.nota2 <= 0 || alumnos[i].nota.nota2 > 10) {
                printf("La nota del segundo parcial no es válida. Intente nuevamente: ");
                scanf("%d", &alumnos[i].nota.nota2);
            }

            alumnos[i].nota.promedio = (float)(alumnos[i].nota.nota1 + alumnos[i].nota.nota2) / 2;

        } while (alumnos[i].nota.promedio <= 0 || alumnos[i].nota.promedio > 10);

        fwrite(&alumnos[i], sizeof(Alumno), 1, pf);
        i++;

        printf("Ingrese un nuevo DNI o 0 para finalizar: ");
        do {
            scanf("%d", &dniTemp);
            if (dniTemp < 0) {
                printf("El valor ingresado no es válido. Intente nuevamente: ");
                scanf("%d", &dniTemp);
            }
        } while (dniTemp < 0);
    }

    fclose(pf);
    lectura();
    return 0;
}

void lectura()
{
    FILE *pf;
    Alumno alumnos;

    pf = fopen("ALUMNOS.dat", "rb");
    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    fread(&alumnos, sizeof(Alumno), 1, pf);
    while(!feof(pf)) {
        printf("Nombre y apellido: %s\n", alumnos.nombreCompleto);
        printf("DNI: %d\n", alumnos.dni);
        printf("Notas: %d, %d\n", alumnos.nota.nota1, alumnos.nota.nota2);
        printf("Promedio: %.2f\n", alumnos.nota.promedio);

        fread(&alumnos, sizeof(Alumno), 1, pf);
    }
    fclose(pf);
}
