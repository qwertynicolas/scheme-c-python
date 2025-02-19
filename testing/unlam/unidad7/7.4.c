#include <stdio.h>
#define SIZE 5

int iguales (int v1[], int v2[])
{
    int igualdad = 0;

    int i;

    for (i = 0; i < SIZE; ++i) {
        if (v1[i] == v2[i]) {
            ++igualdad;
        }
    }

    if (igualdad == SIZE) {
        return 1;
    }

    return 0;
}

int main (void)
{
    int v1 [SIZE] = {2, 3, 5, 7, 11};
    int v2 [SIZE] = {2, 3, 9, 7, 11};

    if (iguales(v1, v2)) {
        printf("Los vectores son iguales.");
    } else {
        printf("Los vectores son NO iguales.");
    }

    return 0;
}
