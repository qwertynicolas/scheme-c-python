/* Confeccionar un programa que solicite el ingreso de un número entero positivo de 4 cifras y pueda calcular
e informar la suma de sus dígitos hasta llegar a una sola cifra. Ej:2561 → 5 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1, suma;

    printf("Ingrese un número entero de 4 cifras: ");
    scanf("%d", &n1);

    if (n1 < 1000 || n1 > 9999){
        printf("El número no es de 4 cifras");
        return 1;
    }

    while (n1 >= 10) {
        suma = 0;
        while (n1 > 0) {
            suma += n1 % 10;
            n1 /= 10;
        }

        n1 = suma;

    }

    printf("La suma de los dígitos hasta llega a una sola cifra es: %d\n", n1); //usar el 2561 para verificar si es que el resultado da 5 como se pide en la consigna, clever trick

    return 0;
}