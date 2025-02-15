#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char w1;
    int vocal = 0;

    printf("Ingrese un carácter: ");
    scanf(" %c", &w1);

    if (w1 == 'a') {
        vocal = 1;
    } else if (w1 == 'e') {
        vocal = 1;
    } else if (w1 == 'i') {
        vocal = 1;
    } else if (w1 == 'o') {
        vocal = 1;
    } else if (w1 == 'u') {
        vocal = 1;
    }

    if (vocal == 1) {
        printf("El carácter es una vocal.\n");
    }

    printf("Valor en ASCII: %d", w1);

    return 0;
}
