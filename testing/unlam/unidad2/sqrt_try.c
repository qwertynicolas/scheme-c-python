#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TOLERANCE 0.00001

double square(double x)
{
    return x * x;
}

int goodEnough (double guess, int radicando)
{
    double difference = fabs(square(guess) - radicando);

    if (difference < TOLERANCE) {
        return 1;
    } else {
        return 0;
    }
}

double improve (double guess, int radicando)
{
    return (guess + (radicando / guess)) / 2;
}

double iteration(double guess, int radicando)
{
    if (goodEnough (guess, radicando)) {
        return guess;
    } else {
        return iteration (improve(guess, radicando), radicando);
    }

    return 0;
}

int main(void)
{
    double guess = 1.0;
    int radicando;
    double raiz;

    printf("Ingrese el radicando: ");
    scanf("%d", &radicando);

    raiz = iteration(guess, radicando);

    printf("La raíz es: %.2f", raiz);

    return 0;

}
