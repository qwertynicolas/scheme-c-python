/* Ingresar un número entero mayor a 0. Debe dibujar una pirámide con * con tantas filas como el número
indicado. En cada fila se va incrementando la cantidad de asteriscos de 2 en 2.
Por ejemplo, si se ingresa el número 5 debe mostrar en pantalla:
*
***
*****
*******
********* */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1;

    printf("Ingrese el número de filas que desea dibujar: ");
    scanf("%d", &num1);

    if (num1 <= 0) {
        printf("El número ingresado no es válido.\n");
        return 1;
    }

    for (int i = 0; i < num1; ++i) {
        for (int j = 0; j < num1 - i - 1; ++j) { // esto es para que sea centrado y darle una mejor estética, no es necesario
            printf(" ");
            }
        for (int k = 0; k < 2 * i + 1; ++k) { // esto es lo importante 
            printf("*");
        }

        
        printf("\n");
    }

    return 0;
}