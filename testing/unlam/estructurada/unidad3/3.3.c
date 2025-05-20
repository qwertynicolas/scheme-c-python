#include <stdio.h>
#include <string.h>
#include <strings.h>

int search(char nombres[][20], int dnis[], int size)
{
    char nombreBuscado[20];
    int i;

    printf("Ingrese un nombre a buscar o NOBUSCARMAS para finalizar: ");
    fgets(nombreBuscado, 20, stdin);

    size_t len = strlen(nombreBuscado);

    if (len > 0 && nombreBuscado[len-1] == '\n')
        nombreBuscado[len-1] = '\0';

    if (strcasecmp(nombreBuscado, "FIN") != 0) {
        for (i = 0; i < size; i++) {
            if (strcasecmp(nombres[i], nombreBuscado) == 0) {
                printf("D.N.I del alumno: %d\n", dnis[i]);
                return 1;
            }
        }
    }

    return 0;
}

void sorting(char nombres[][20], int size)
{
    int i, j, swap;
    char nombreTemp[20];

    do {
        swap = 0;
        for (i = 0; i < size-1; i++) {
            for (j = 0; j < size-1-i; j++) {
                if (strcasecmp(nombres[j], nombres[j+1]) > 0) {
                    strcpy(nombreTemp, nombres[j]);
                    strcpy(nombres[j], nombres[j+1]);
                    strcpy(nombres[j+1], nombreTemp);

                    swap = 1;
                }
            }
        }
    } while (swap != 0);

}

int main(void)
{
    char nombres[50][20];
    int dnis[50];
    int i = 0;
    size_t len;

    printf("Ingrese el nombre del alumno: ");
    fgets(nombres[i], 20, stdin);

    len = strlen(nombres[i]);

    if (len > 0 && nombres[i][len-1] == '\n')
        nombres[i][len-1] = '\0';

    while (strcasecmp(nombres[i], "FIN") != 0 && i < 50) {
        printf("Ingrese el D.N.I del alumno: ");
        scanf("%d", &dnis[i]);

        while (dnis[i] < 0) {
            printf("El D.N.I ingresado no es válido. Intente nuevamente: ");
            scanf("%d", &dnis[i]);
        }

        while (getchar() != '\n');
        i++;

        printf("Ingrese un nuevo nombre o FIN para finalizar: ");
        fgets(nombres[i], 20, stdin);

        len = strlen(nombres[i]);

        if (len > 0 && nombres[i][len-1] == '\n')
            nombres[i][len-1] = '\0';
    }

    while (search(nombres, dnis, i) != 0) {
        // si la función devuelve un 1 la función sigue corriendo
        // si devuelve 0 el while finaliza
    }

    sorting(nombres, i);

    int j;

    printf("Listado de alumnos:\n");
    for (j = 0; j < i; j++) {
        puts(nombres[j]);
    }

    return 0;
}
