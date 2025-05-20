#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char frase[500];

    printf("Ingrese una frase de menos de 500 caracteres: ");
    fgets(frase, 500, stdin);

    int i, words = 0;

    size_t len = strlen(frase);

    if (len > 0 && frase[len-1] == '\n')
        frase[len-1] = '\0';

    for (i = 0; i < 500; i++) {
        if (frase[i] == ' ')
            words++;
    }

    printf("La frase contiene %d palabras.\n", words);

    return 0;

}
