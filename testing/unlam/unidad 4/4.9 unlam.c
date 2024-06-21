/* Confeccionar un programa que permita ingresar un carácter alfanumérico y determine e informe si lo
ingresado corresponde a una vocal, con el mensaje “VOCAL”. y su correspondiente valor numérico en ASCII. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    char caracter;

    printf("Ingrese un carácter alfanúmerico: ");
    scanf("%c", &caracter);

    switch (caracter) {
        case 'a' :
        case 'e' :
        case 'i' :
        case 'o' :
        case 'u' :
        case 'A' :
        case 'E' :
        case 'I' :
        case 'O' :
        case 'U' : printf("Corresponde a una vocal.\n");
        break;
        default : printf("NO corresponde a una vocal.\n");
    }   

    printf("Su valor númerico en ASCII es: %d.\n", caracter);
    return 0;
}
