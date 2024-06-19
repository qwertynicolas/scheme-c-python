/* Confeccionar un programa que permita convertir grados sexagesimales a radianes y viceversa, según el
valor de un código que se ingresa junto al valor. Si código = 1 se ingresan grados, si es 2 se ingresan radianes.

1 radian = 180/𝜋 grados
1 grado = 𝜋/180 radianes */

#include <stdio.h>
#include <stdlib.h>

int main() {

    double valor, convertido;
    int codigo;
    const double pi = 3.14159265359; // no es necesario esto

    printf("Ingrese un valor númerico en grados o radianes: ");
    scanf("%lf", &valor);
    printf("Ingrese el código de representación. 1 = grados o 2 = radianes: ");
    scanf("%d", &codigo);

   if (codigo == 1) {
        convertido = valor * (pi / 180);
        printf("El valor en radianes es: %.6f\n", convertido);
   } else if (codigo == 2) {
        convertido = valor * (180 / pi);
        printf("El valor en grados es: %.6f\n", convertido);
   } else {
    printf("Código no válido.\n");
    return 1;
   } 

    return 0;
}