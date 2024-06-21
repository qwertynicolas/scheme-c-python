/* Ingresar un número entero mayor a 0. Debe dibujar un triángulo rectángulo con * con tantas filas como
el número indicado. En cada fila se va incrementando la cantidad de asteriscos. Por ejemplo, si se ingresa el
número 6 debe mostrar en pantalla:
*
**
***
****
*****
****** */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1;
    int asteriscos;

    printf("Ingrese el número de filas que desea dibujar: ");
    scanf("%d", &num1);

    if (num1 <= 0) {
        printf("El número ingresado no es válido.\n");
        return 1;
    }

    for (int i = 0; i < num1; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}