#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int vocales = 0;
    char letra;
    int i;

    for (i = 0; i <= 10; ++i) {
        printf("Ingrese una letra: ");
        scanf(" %c", &letra);

        if (letra == 'a' || letra == 'A') {
            ++vocales;
        } else if (letra == 'e' || letra == 'E') {
            ++vocales;
        } else if (letra == 'i' || letra == 'I') {
            ++vocales;
        } else if (letra == 'o' || letra == 'O') {
            ++vocales;
        } else if (letra == 'u' || letra == 'U') {
            ++vocales;
        }
    }

    printf("Se ingreson %d vocales", vocales);

    return 0;
}
