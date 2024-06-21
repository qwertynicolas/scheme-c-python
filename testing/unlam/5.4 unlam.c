//Se ingresan 100 letras. Determinar la cantidad de vocales ingresadas.

#include <stdio.h>
#include <stdlib.h>

int main() { //si se ingresa 'ñ' o 'Ñ' ocurre un error y la cuenta doble

    char letras[100];
    int vocales = 0;
    char letra;

    for (int i = 0; i < 100; ++i) {
        printf("Ingrese una letra (%d de 100): ", i + 1);
        scanf(" %c", &letra);
        letras[i] = letra;

        if (letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e' || letra == 'I' || letra == 'i' || letra == 'O' || letra == 'o' || letra == 'U' || letra == 'u') {
            vocales++;
        } 
    }

    printf("La cantidad de vocales ingresadas es de %d.\n", vocales);

    return 0;
}