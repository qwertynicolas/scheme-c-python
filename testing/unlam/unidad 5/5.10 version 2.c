// segunda versión del 5.11 usando un do while

#include <stdio.h>

int main() {
    int N;
    int maximo = 12;
    int ceros = 0;
    int contador_positivos = 0;
    int contador_negativos = 0;
    float suma_positivos = 0;
    float suma_negativos = 0;

    do {
        printf("Ingrese un valor entero menor a 12: ");
        scanf("%d", &N);

        if (N <= 0 || N >= 12) {
            printf("El valor de N no es válido. Por favor, ingrese un valor válido.\n");
        }
    } while (N <= 0 || N >= 12);

    for (int i = 0; i < N; ++i) {
        float numero;
        printf("Ingrese el número real %d de %d: ", i + 1, N);
        scanf("%f", &numero);

        if (numero < 0) {
            suma_negativos += numero;
            ++contador_negativos;
        } else if (numero > 0) {
            suma_positivos += numero;
            ++contador_positivos;
        } else {
            ++ceros;
        }
    }

    float promedio_negativos = contador_negativos > 0 ? suma_negativos / contador_negativos : 0;
    float promedio_positivos = contador_positivos > 0 ? suma_positivos / contador_positivos : 0;

    printf("El promedio de números negativos es de %.2f.\n", promedio_negativos);
    printf("El promedio de números positivos es de %.2f.\n", promedio_positivos);
    printf("Hubo %d ceros.\n", ceros);

    return 0;
}
