/* Confeccionar un programa que solicite el ingreso de un valor entero N < 12 y luego una lista de N números
reales sobre la cual debe calcular:
a. el promedio de los positivos.
b. el promedio de los negativos.
c. la cantidad de ceros. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    int ceros = 0;
    int contador_positivos = 0;
    int contador_negativos = 0;
    float suma_positivos = 0;
    float suma_negativos = 0;

    printf("Ingrese un valor entero menor a 12: ");
        scanf("%d", &N);

    if (N <= 0 || N >= 12) {
        printf("El valor no es válido.\n");
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        float numero;
        printf("Ingrese un número real (%d de %d): ", i + 1, N);
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
    printf("Se ingresaron %d ceros.\n", ceros);

    return 0;
    
}