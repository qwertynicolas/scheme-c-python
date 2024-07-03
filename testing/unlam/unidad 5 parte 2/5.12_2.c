/* Confeccionar un programa que permita el ingreso de 6 ternas de valores enteros.  
a. de cada terna informar el mayor valor y su orden en la terna.  
b. de cada terna informar cuantos valores son múltiplos de 7.  
c. de las 6 ternas determinar e informar el promedio de los primeros valores de cada una. */

#include <stdio.h>

int main() {

    int ternas[6][3];
    int i, j;

    for (i = 0; i < 6; ++i) {
        printf("Ingrese los valores de la terna Nº%d: ", i + 1);
        for (j = 0; j < 3; ++j) {
            scanf("%d", &ternas[i][j]); 
        }
    }

    int suma_primeros_valores = 0;

    for (i = 0; i < 6; ++i) {
        int mayor_valor = ternas[i][0];
        int posicion_mayor = 1;
        int multiplos7 = 0;

        for (j = 0; j < 3; ++j) { // mayor valor y su posicion
            if (ternas[i][j] > mayor_valor) {
                mayor_valor = ternas[i][j];
                posicion_mayor = j + 1;
            }

            if (ternas[i][j] % 7 == 0) {
                ++multiplos7;
            }
        }

        suma_primeros_valores += ternas[i][0];

        printf("Terna Nº%d: Mayor valor: %d. Posicion: %d\n", i + 1, mayor_valor, posicion_mayor);

        printf("Terna Nº%d: Múltiplos de 7: %d\n", i + 1, multiplos7);
    }

    float promedio;
    promedio = suma_primeros_valores / (float)6;
    printf("El promedio de los primeros valores es %.2f\n", promedio);

    return 0;
}