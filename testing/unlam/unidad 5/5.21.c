/* Tomando como base el ejercicio anterior ingresar un número entero mayor a 0 y dibujar un rombo con
*. Por ejemplo, si se ingresa el número 5 dibuja la pirámide de 5 filas y luego completa el rombo al ir
decrementando la cantidad de asteriscos.

        *
       ***
      *****
     *******
    *********
     *******
      *****
       ***
        * 
         
        */


#include <stdio.h>
#include <stdlib.h>

int main() {

    int num;

    printf("¿De cuántas filas desea dibujar el rombo? : ");
    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num - i - 1; ++j) {
            printf(" ");
        }

        for (int k = 0; k < 2 * i + 1; ++k) {
            printf("*");
          }
            printf("\n");

        }

        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < num ; ++j) {
                printf("*");
            }
        }

        printf("\n");

    


    return 0;
}