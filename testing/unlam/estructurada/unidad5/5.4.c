#include <stdio.h>

void cargarVector (int vector[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Ingrese el valor Nº%d: ", i+1);
        scanf("%d", vector+i);
    }
}

void mostrarVector (int vector[], int size)
{
    int i;
    printf("Vector: ");
    for (i = 0; i < size; i++) {
        printf("%d ", *(vector+i));
    }
    printf("\n");
}

int *buscarVector (int vector[], int size, int dato)
{
    int i = 0, flag = 0;
    int posicion = -1;

    while (i < size && flag == 0) {
        if ( *(vector+i) == dato) {
            flag = 1;
            posicion = i;
        } else {
            i++;
        }
    }

   int *pdato = NULL;

   if (posicion != -1)
       pdato = vector+posicion;

   return pdato;
}

int main(void)
{
    int vector[10];

    cargarVector(vector, 10);
    mostrarVector(vector, 10);

    int num = 1;
    int *pnum;
    int i;
    int flag;

    while (num > 0) {
        printf("Ingrese un elemento a buscar del vector o 0 si desea finalizar: ");
        scanf("%d", &num);

        pnum = buscarVector(vector, 10, num);
        i = 0;
        flag = 0;
        while (pnum != NULL && i < 10 && flag == 0) {
            if (vector+i == pnum) {
                printf("Posición: %d\n", i+1);
                flag = 1;
            } else {
                i++;
            }
        }

        if (pnum == NULL && num > 0)
            printf("No se encontró el elemento.\n");
    }

    return 0;
}
