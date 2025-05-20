#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char cadena[21];
    printf("Ingrese un string de no más de 20 caracteres.\n");
    fgets(cadena, 21, stdin);
    printf("La cadena ingresada contiene: %ld caracteres.\n", strlen(cadena));

    char original[15], copia[15];
    printf("Ingrese una cadena que luego será copiada: ");
    fgets(original, 15, stdin);
    strcpy(copia, original);
    printf("String original: %sCopia: %s\n", original, copia);

    char receptor[40] = "Se agrego lo siguiente";
    char dador[] = ", me agregue";
    printf("Las cadenas por separado son: \n\t %s\n\t %s", receptor, dador);
    strcat(receptor, dador);
    printf("\nLas cadenas unificadas son: \n\t %s\n", receptor);

    char cadena1[30], cadena2[30];
    printf("Ingrese la primera cadena: ");
    fgets(cadena1, 30, stdin);
    printf("Ingrese la segunda cadena: ");
    fgets(cadena2, 30, stdin);

    if (strcmp(cadena1, cadena2) == 0)
        printf("Las cadenas son iguales.");
    else
        if (strcmp(cadena1, cadena2) > 0)
            printf("La cadena 1 es mayor que la cadena 2.");
        else
            printf("La cadena 2 es mayor que la cadena 1.");

    return 0;
}
