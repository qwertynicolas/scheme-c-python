#include <stdio.h>
#include <math.h>
#define SIZE 10

void generarVA (float vA[])
{
    int i;

    for (i = 0; i < SIZE; ++i) {
        printf("Ingrese el valor Nº%d para VA: ", i+1);
        scanf("%f", &vA[i]);
    }
}

void generarVB (float vB[], float vA[])
{
    int i;

    for (i = 0; i < SIZE; ++i) {
        if (vA[i] < 0) {
            vB[i] = 0;
        } else {
            vB[i] = sqrt(vA[i]);
        }
    }
}

void generarVC (float vC[], float vA[], float vB[])
{
    int i;

    for (i = 0; i < SIZE; ++i) {
        vC[i] = vA[i] + vB[i];
    }
}

void generarVD (float vD[], float vC[])
{
    int i, size;
    size = SIZE - 1;

    for (i = 0; i < SIZE; ++i) {
        vD[i] = vC[size - i];
    }

}

void generarVE (float vE[], float vA[])
{
    int i;
    int j = 0;

    for (i = 0; i < SIZE; ++i) {
        if (vA[i] < 0) {
           vE[j] = vA[i];
           ++j;
        }
    }
}

void mostrarVectores (float vA[], float vB[], float vC[], float vD[], float vE[], int negatives)
{
    int i;

    printf("Vector A: ");

    for (i = 0; i < SIZE; ++i) {
        printf("%.2f ", vA[i]);
    }

    printf("\nVector B: ");

    for (i = 0; i < SIZE; ++i) {
        printf("%.2f ", vB[i]);
    }

    printf("\nVector C: ");

    for (i = 0; i < SIZE; ++i) {
        printf("%.2f ", vC[i]);
    }

    printf("\nVector D: ");

    for (i = 0; i < SIZE; ++i) {
        printf("%.2f ", vD[i]);
    }

    printf("\nVector E: ");

    for (i = 0; i < negatives; ++i) {
        printf("%.2f ", vE[i]);
    }

}

int main (void)
{
    float vA[SIZE], vB[SIZE];

    generarVA(vA);

    generarVB(vB, vA);

    float vC[SIZE];

    generarVC(vC, vB, vA);

    float vD[SIZE];

    generarVD(vD, vC);

    int negatives = 0;
    int i;

    for (i = 0; i < SIZE; ++i) {
        if (vA[i] < 0) {
            ++negatives;
        }
    }

    float vE[negatives];

    generarVE(vE, vA);

    mostrarVectores(vA, vB, vC, vD, vE, negatives);

    printf("\n");

    float mayor = 0;
    int posicionMayor = 0;

    for (i = 0; i < SIZE; ++i) {
        if (vA[i] > mayor) {
            mayor = vA[i];
            posicionMayor = i;
        }
    }

    printf("Mayor valor de VA: %.2f. Posición: %d", mayor, posicionMayor+1);

    return 0;
}
