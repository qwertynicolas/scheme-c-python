#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n1, n2, n3;

    printf("Ingrese el primer número: ");
    scanf("%d", &n1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &n2);
    printf("Ingrese el tercer número: ");
    scanf("%d", &n3);

    int first, second, third;

    if (n1 < n2 && n1 < n3) {
        first = n1;
    } else if (n2 < n3) {
        first = n2;
    } else {
        first = n3;
    }

    if (n1 != first && (n1 < n2 || n1 < n3)) {
        second = n1;
    } else if (n2 != first && (n2 < n3 || n2 < n1)) {
        second = n2;
    } else if (n3 != first) {
        second = n3;
    }

    if (n1 != first && n1 != second) {
        third = n1;
    } else if (n2 != first && n2 != second) {
        third = n2;
    } else if (n3 != first && n3 != second) {
        third = n3;
    }

    printf("%d\n", first);
    printf("%d\n", second);
    printf("%d", third);

    return 0;
}
