#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarVector (int [], int);
int *mayorPointer (int [], int, int*);
void mostrarVector(int [], int);

int main(void)
{
    srand(time(NULL));

    int vector[10];

    cargarVector(vector, 10);
    mostrarVector(vector, 10);

    int *pmayor;
    int x = 0;
    pmayor = mayorPointer(vector, 10, &x);
    if (pmayor != NULL) {
        printf("Mayor valor: %d. Posición: %d\n", *pmayor, x+1);
    }

    return 0;
}

void cargarVector(int vector[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        *(vector+i) = rand() % 999;
    }
}

int *mayorPointer(int vector[], int size, int *posicion)
{
    int i;
    int *pmayor = vector+0;

    for (i = 1; i < size; i++) {
        if (*(vector+i) > *pmayor) {
            pmayor = vector+i;
            *posicion = i;
        }
    }

    return pmayor;
}

void mostrarVector(int vector[], int size)
{
    int i;
    printf("Vector: ");
    for (i = 0; i < size; i++) {
        printf("%d ", *(vector+i));
    }
    printf("\n");
}
