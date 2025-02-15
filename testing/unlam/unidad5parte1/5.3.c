#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int sum = 0;
    int i;
    int num;

    for (i = 0; i <= 10; ++i) {
        printf("Ingrese un número entero: ");
        scanf("%d", &num);
        if (num % 2 == 0) {
            sum += num;
        }
    }

    float average = (float)sum / 10;

    printf("El promedio es %.5f", average);

    return 0;
}
