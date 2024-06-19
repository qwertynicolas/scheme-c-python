/* Confeccionar un programa que permita ingresar un par de valores enteros a y b, que
corresponden a las temperaturas registradas en un día y un código que indica la operación que se
debe realizar con dichos valores.

El código de operación puede variar entre 1 y 8. Según el valor del código se pide calcular e informar:

Valor Còdigo           Calcular
   1                    a + b
   2,4 ú 8              a - b
   3 ó 5                a * b
   7                    a / b
   6                    a % b
  < 1 ó > 8             rechazar


Por cada código ingresado imprimir los valores leídos y el resultado obtenido, con leyendas.
 */


#include <stdio.h>
#include <stdlib.h>

int main () {


    int a, b, codigo;

    printf("Ingrese el primer valor: ");
    scanf("%d", &a);
    printf("Ingrese el segundo valor: ");
    scanf("%d", &b);
    printf("Ingrese el código de operación a realizar: ");
    scanf("%d", &codigo);

    switch (codigo) {
        case 1 : printf("El resultado es %d\n", a + b);
        break;
        case 4 :
        case 8 : 
        case 2 : printf("El resultado es %d\n", a - b);
        break;
        case 5 :
        case 3 : printf("El resultado es %d\n", a * b);
        break;
        case 7 : printf("El resultado es %d\n", a / b);
        break;
        case 6 : printf("El resultado es %d\n", a % b);
        break;
        default : printf("Código inexistente.\n");
    }

    return 0;
}