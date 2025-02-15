#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int triangulo = 0;
    float l1,l2,l3;

    printf("Ingrese la medida del primer lado: ");
    scanf("%f", &l1);
    if (l1 < 0) {
        printf("La medida no es válida.");
        return main();
    }

    printf("Ingrese la medida del segundo lado: ");
    scanf("%f", &l2);
    if (l2 < 0) {
        printf("La medida no es válida.");
        return main();
    }

    printf("Ingrese la medida del tercado lado: ");
    scanf("%f", &l3);
    if (l3 < 0) {
        printf("La medida no es válida.");
        return main();
    }

    if ((l1 < (l2 + l3)) && (l2 < (l1 + l3)) && (l3 < (l1 + l2))) {
        triangulo = 1;
    }

    if (triangulo == 0) {
        printf("Los lados NO conforman un triángulo.");
    } else {
        printf("Los lados conforman un triángulo");
    }

    return 0;
}
