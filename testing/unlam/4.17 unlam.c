/* Confeccionar un programa que pueda determinar el importe a pagar por una prestación médica según su
código. Los importes se cobran según la siguiente tabla:
Código   Importe
 A         20
 D         40
 F         60
 M        150
 T        150
Se debe ingresar el número de historia del paciente y el código de la prestación. Se debe emitir un ticket
con el número de la historia, el código y el importe a pagar. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num_historia;
    char codigo;

    printf("Ingrese su número de historia: ");
    scanf("%d", &num_historia);
    printf("Ingrese el código de prestación médica: ");
    scanf(" %c", &codigo);

    switch (codigo) {
        case 'A' : printf("NÚMERO DE HISTORIA: %d\t  CÓDIGO: %c\t IMPORTE: $%d\n", num_historia, codigo, 20);
        break;
        case 'D' : printf("NÚMERO DE HISTORIA: %d\t  CÓDIGO: %c\t IMPORTE: $%d\n", num_historia, codigo, 40);
        break;
        case 'F' : printf("NÚMERO DE HISTORIA: %d\t  CÓDIGO: %c\t IMPORTE: $%d\n", num_historia, codigo, 60);
        break;
        case 'T' :
        case 'M' : printf("NÚMERO DE HISTORIA: %d\t  CÓDIGO: %c\t IMPORTE: $%d\n", num_historia, codigo, 150);
        break;
        default : printf("El código no es válido.\n");
    }

    return 0;
}