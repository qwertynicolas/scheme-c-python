#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[31];
    int dni;
    float promedio;
} Alumnos;

int main(void)
{
    Alumnos reg;
    FILE *fp;
    size_t len;

    fp = fopen("alumnos.csv", "wt");

    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    fprintf(fp, "Nombre;DNI;Promedio\n");

    printf("Ingrese DNI 0 para terminar: ");
    scanf("%d", &reg.dni);

    while (reg.dni > 0) {
        printf("Ingrese el nombre: ");
        getchar();
        fgets(reg.nombre, 31, stdin);
        len = strlen(reg.nombre);

        if (len > 0 && reg.nombre[len-1] == '\n')
            reg.nombre[len-1] = '\0';

        printf("Ingrese el promedio: ");
        scanf("%f", &reg.promedio);
        fprintf(fp, "%s;%d;%.2f\n", reg.nombre, reg.dni, reg.promedio);

        printf("Ingrese DNI o 0 para terminar: ");
        scanf("%d", &reg.dni);
    }

    fclose(fp);
    return 0;
}
