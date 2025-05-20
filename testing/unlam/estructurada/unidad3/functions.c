#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

void carga(char vn[][11], int cant)
{
    int i;
    size_t len;
    for (i = 0; i < cant; i++) {
        printf("ingrese el nombre número %d: ", i+1);
        if (fgets(vn[i], 11, stdin) == NULL) {
            perror("Error leyendo entrada");
            exit(EXIT_FAILURE);
        }

        len = strlen(vn[i]);

        if (len > 0 && vn[i][len-1] == '\n') {
            vn[i][len-1] = '\0';
        }
    }
}

void show(char vn[][11], int cant)
{
    int i;
    for (i = 0; i < cant; i++)
        puts(vn[i]);
}

int buscar(char vn[][11], char buscado[][11], int cant)
{
    int i;

    for (i = 0; i < cant; i++) {
        if (strcasecmp(vn[i], buscado[0]) == 0)
            return i;
    }

    return -1;
}

void ordenar(char vn[][11], int cant)
{
    int i, j;
    char temp[11];

    for (i = 0; i < cant-1; i++) {
        for (j = 0; j < cant-1-i; j++) {
            if (strcasecmp(vn[j], vn[j+1]) > 0) {
                strcpy(temp, vn[j]);
                strcpy(vn[j], vn[j+1]);
                strcpy(vn[j+1], temp);
            }
        }
    }
}

int main(void)
{
    int pos;
    char nombres[5][11];
    char abuscar[1][11];

    carga(nombres, 5);

    printf("Listado de nombres ingresado:\n");

    show(nombres, 5);

    printf("\nIngrese un nombre a buscar (FIN para terminar): ");
    fgets(abuscar[0], 11, stdin);

    size_t largo;

    largo = strlen(abuscar[0]);

    if (largo > 0 && abuscar[0][largo-1] == '\n') {
        abuscar[0][largo-1] = '\0';
    }

    while (strcasecmp(abuscar[0], "FIN") != 0) {
        pos = buscar(nombres, abuscar, 5);

        if (pos != -1)
            printf("El nombre se encuentra en el vector.");
        else
            printf("El nombre NO se encuentra en el vector.");

        printf("Ingrese un nombre a buscar (FIN para terminar): ");
        fgets(abuscar[0], 11, stdin);

        largo = strlen(abuscar[0]);

        if (largo > 0 && abuscar[0][largo-1] == '\n') {
            abuscar[0][largo-1] = '\0';
        }
    }

    ordenar(nombres, 5);

    printf("Listado de nombres ordenado:\n");
    show(nombres, 5);

    return 0;
}
