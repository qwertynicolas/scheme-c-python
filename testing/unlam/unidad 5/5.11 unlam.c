/* Ingresar 18 valores de temperatura distintos de cero. Se pide determinar e informar cuantas ternas (tres
valores seguidos) de valores positivos y cuantas de negativos hay. */

#include <stdio.h>
#include <stdlib.h>

int main () {

    int ternas_negativas = 0;
    int ternas_positivas = 0;
    int valores = 18;
    int negativos = 0;
    int positivos = 0;

    for (int i = 0; i < valores; ++i) {
        float temp;
        printf("Ingrese un valor de temperatura (%d de %d): ", i + 1, valores);
        scanf("%f", &temp);

        if (temp == 0) {
            printf("El valor ingresado no es válido.\n");
            --i;
            continue;
        } 

        if (temp < 0) {
            ++negativos;
        } 

        if (temp > 0) {
            ++positivos;
        }
       
    }

        ternas_negativas = negativos > 0 ? (ternas_negativas + negativos) / 3 : 0;
        ternas_positivas = positivos > 0 ? (ternas_positivas + positivos) / 3 : 0; 

        printf("Hay %d ternas negativas y %d ternas positivas.\n", ternas_negativas, ternas_positivas);

    return 0;
}