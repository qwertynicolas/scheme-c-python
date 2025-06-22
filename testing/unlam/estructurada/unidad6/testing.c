#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dni;
    char nombreCompleto[31];
    int nota1;
    int nota2;
    float promedio;
} Alumnos;

void cargar();
void leer();

int main(void)
{
    cargar();
    leer();
    return 0;
}

void cargar()
{
    FILE *pf;
    Alumnos alumno;
    size_t len;

    pf = fopen("Alumno.dat", "wb");
    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    printf("Ingresar DNI: ");
    do {
        scanf("%d", &alumno.dni);
        if (alumno.dni < 0)
            printf("El valor ingresado no es válido. Intente nuevamente: ");
    } while (alumno.dni < 0);

    getchar();
    while (alumno.dni != 0) {
        printf("Ingrese nombre y apellido: ");
        fgets(alumno.nombreCompleto, 31, stdin);
        len  = strlen(alumno.nombreCompleto);
        if (len > 0 && alumno.nombreCompleto[len-1] == '\n')
            alumno.nombreCompleto[len-1] = '\0';

        printf("Ingrese nota del primer parcial: ");
        scanf("%d", &alumno.nota1);
        printf("Ingrese nota del segundo parcial: ");
        scanf("%d", &alumno.nota2);

        alumno.promedio = (float)(alumno.nota1 + alumno.nota2) / 2;

        fwrite(&alumno, sizeof(Alumnos), 1, pf);

        printf("Ingrese un nuevo DNI o 0 para finalizar: ");
        do {
            scanf("%d", &alumno.dni);
            if (alumno.dni < 0)
                printf("El número ingresado no es válido. Intente nuevamente: ");
        } while (alumno.dni < 0);
    }

    fclose(pf);
}

void leer()
{
    FILE *pf;
    Alumnos alumno;

    pf = fopen("Alumno.dat", "rb");
    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    fread(&alumno, sizeof(Alumnos), 1, pf);

    while (feof(pf) == 0) {
        printf("\nNombre y apellido: %s\n", alumno.nombreCompleto);
        printf("DNI: %d\n", alumno.dni);
        printf("Nota primer parcial: %d. Nota segundo parcial: %d\n", alumno.nota1, alumno.nota2);
        printf("Promedio: %.2f\n", alumno.promedio);

        fread(&alumno, sizeof(Alumnos), 1, pf);
    }

    fclose(pf);
}
