#include <stdio.h>

void combineVectors (int v1[5], int v2[5], int result[10])
{
    int i;

    for (i = 0; i < 5; ++i) {
        result[i] = v1[i];
    }

    for (i = 0; i < 5; ++i) {
        result[i+5] = v2[i];
    }

}

int main (void)
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[5] = {6, 7, 8, 9, 10};

    int i;

    int newVector[10];

    combineVectors(v1, v2, newVector);

    printf("Nuevo vector: ");
    for (i = 0; i < 10; ++i) {
        printf("%d ", newVector[i]);
    }

    /* printf("\n"); */

    return 0;

}
