#include <stdio.h>
#define ARTICULOS 10
#define HALT 77

void generarVB (int newVector[], int oldVector[], int size)
{
    int i, k, j = 0;

    for (i = 0; i < ARTICULOS; ++i) {
        if (oldVector[i] != 0) {
            newVector[j] = oldVector[i];
            ++j;
        }
    }

    printf("Vector B: ");
    for (k = 0; k < size; ++k) {
        printf("%d ", newVector[k]);
    }

    printf("\n");
}

void generarVC (int newVector[], int oldVector[], int size)
{
    int i, k, j = 0;

    for (i = 0; i < ARTICULOS; ++i) {
        if (oldVector[i] != 0) {
            newVector[j] = oldVector[i];
            ++j;
        }
    }

    printf("Vector C: ");
    for (k = 0; k < size; ++k) {
        printf("%d ", newVector[k]);
    }

    printf("\n");
}

void generarVD (int newVector[], int oldVector[], int size)
{
    int i, k, j = 0;

    for (i = 0; i < ARTICULOS; ++i) {
        if (oldVector[i] != 0) {
            newVector[j] = oldVector[i];
            ++j;
        }
    }

    printf("Vector D: ");
    for (k = 0; k < size; ++k) {
        printf("%d ", newVector[k]);
    }

    printf("\n");
}

void generarVA (int vA[])
{
    int i, j, k, l, codigo, deposito, stock, reposicion;
    char clase;

    i = j = k = l = 0;

    // j - VB
    // l - VC
    // k - VD

    int vB[ARTICULOS], vC[ARTICULOS], vD[ARTICULOS];

    printf("Ingrese el código del artículo (1 - 500): ");
    scanf("%d", &codigo);

    while (codigo < 1 || codigo > 500) {
        printf("El código no es válido. Vuelva a intentar: ");
        scanf("%d", &codigo);
    }

    while (codigo != HALT) {
        printf("Ingrese la clase del artículo (A - D): ");
        scanf(" %c", &clase);

        while (clase < 'A' || clase > 'D') {
            printf("La clase no es válida. Intente de nuevo: ");
            scanf(" %c", &clase);
        }

        printf("Ingrese el número del depósito (1 - 100): ");
        scanf("%d", &deposito);

        while (deposito < 1 || deposito > 100) {
            printf("El número del depósito no es válido. Intente nuevamente: ");
            scanf("%d", &deposito);
        }

        if (deposito >= 15 && deposito <= 50) {
            vD[k] = codigo;
            ++k;
        }

        printf("Ingrese el stock del artículo (0 - 2000): ");
        scanf("%d", &stock);

        while (stock < 0 || stock > 2000) {
            printf("El stock no es válido. Intente nuevamente: ");
            scanf("%d", &stock);
        }

        if (stock == 0) {
            vB[j] = codigo;
            ++j;
        }

        printf("Ingrese el punto de reposición (500 - 1000): ");
        scanf("%d", &reposicion);

        while (reposicion < 500 || reposicion > 1000) {
            printf("El punto de reposicion no es válida. Intente de nuevo: ");
            scanf("%d", &reposicion);
        }

        if (stock < reposicion) {
            vC[l] = codigo;
            ++l;
        }

        vA[i] = codigo;

        ++i;

        printf("Ingrese un nuevo código o 77 si desea finalizar: ");
        scanf("%d", &codigo);

        while (codigo < 1 || codigo > 500) {
            printf("El código no es válido. Vuelva a intentar: ");
            scanf("%d", &codigo);
        }
    }

    printf("\n");
    int newVB[j], newVC[k], newVD[l];
    generarVB(newVB, vB, j);
    generarVC(newVC, vC, l);
    generarVD(newVD, vD, k);

}

int main (void)
{
    int vA[ARTICULOS];

    generarVA(vA);

    return 0;
}
