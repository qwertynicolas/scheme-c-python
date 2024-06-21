#include <stdio.h>

int main() {
    int ternas_negativas = 0;
    int ternas_positivas = 0;
    int valores = 18;
    int contador_negativos = 0;
    int contador_positivos = 0;
    int consecutivos_positivos = 0;
    int consecutivos_negativos = 0;

    for (int i = 0; i < valores; ++i) {
        float temp;
        printf("Ingrese un valor de temperatura distinto de cero (%d de %d): ", i + 1, valores);
        scanf("%f", &temp);

        if (temp == 0) {
            printf("El valor ingresado no es válido. Por favor, ingrese un valor distinto de cero.\n");
            --i;
            continue;
        } 

        if (temp < 0) {
            ++contador_negativos;
            consecutivos_positivos = 0; 
            if (++consecutivos_negativos == 3) {
                ++ternas_negativas;
                consecutivos_negativos = 0;
            }
        } 

        if (temp > 0) {
            ++contador_positivos;
            consecutivos_negativos = 0; 
            if (++consecutivos_positivos == 3) {
                ++ternas_positivas;
                consecutivos_positivos = 0;
            }
        }
    }

    printf("Hay %d ternas negativas y %d ternas positivas.\n", ternas_negativas, ternas_positivas);

    return 0;
}