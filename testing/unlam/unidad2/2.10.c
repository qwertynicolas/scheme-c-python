#include <stdio.h>
#include <stdlib.h>

#define PI 3.141692
#define FOURTHTHIRDS 1.33333333

int square(int x)
{
    return x * x;
}

int cube (int x)
{
    return square(x) * x;
}

int main(void)
{
    int radio;

    printf("Ingrese el radio del círculo: ");
    scanf("%d", &radio);

    float superficie = PI * square(radio);
    float perimetro = 2 * PI * radio;
    float volumen = FOURTHTHIRDS * PI * cube(radio);

    printf("Superficie: %.2f\n", superficie);
    printf("Perímetro: %.2f\n", perimetro);
    printf("Volúmen: %.2f\n", volumen);

    return 0;

}
