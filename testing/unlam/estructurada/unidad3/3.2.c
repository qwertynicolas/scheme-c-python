#include <stdio.h>
#include <string.h>

int main(void)
{
    char nombre[40];
    char apellido[20];

    printf("Ingrese un nombre: ");
    fgets(nombre, 40, stdin);

    size_t len1 = strlen(nombre);

    if (len1 > 0 && nombre[len1-1] == '\n')
        nombre[len1-1] = '\0';

    printf("Ingrese un apellido: ");
    fgets(apellido, 20, stdin);

    size_t len2 = strlen(apellido);

    if (len2 > 0 && apellido[len2-1] == '\n')
        apellido[len2-1] = '\0';

    if (len1 + len2 + 1 >= 40) {
        printf("Error: Las entradas son muy largas.");
        return 1;
    }

    strcat(nombre, " ");
    strcat(nombre, apellido);

    printf("Nombre y apellido: ");
    puts(nombre);

    return 0;

}
