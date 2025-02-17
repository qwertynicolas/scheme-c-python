#include <stdio.h>

void combineVectors (int v1[5], int v2[5], int result[10])
{
    int i, k, j;
    k = j = 0;

    for (i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            result[i] = v1[k];
            ++k;
        } else {
            result[i] = v2[j];
            ++j;
        }
    }

}

int main (void)
{
    int v1 [5] = {1, 2, 3, 4, 5};
    int v2 [5] = {6, 7, 8, 9, 10};
    int i;
    int result[10];

    combineVectors(v1, v2, result);

    printf("New vector: ");
    for (i = 0; i < 10; ++i) {
        printf("%d ", result[i]);
    }

    return 0;
}
