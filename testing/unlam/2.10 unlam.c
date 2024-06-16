/* Confeccionar un programa que solicite el ingreso del valor del radio (r) de un círculo y con dicho valor calcule
la superficie del círculo, la longitud de la circunferencia (perímetro) y el volumen de la esfera. 
superficie = 𝜋𝑟2, perímetro = 2𝜋𝑟, volúmen = 4/3 𝜋𝑟3³ */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int radio;
    double superficie, perimetro, volumen;
    const double pi = 3.14159265;

    printf("Ingrese el radio del círculo: ");
    scanf("%d", &radio);

    superficie = pi * (radio * radio); // a de haber un operador para expresar el cuadrado/cubo de un numero pero por el momento esto sirve
    perimetro = (2 * pi) * radio;
    volumen = (4.0 / 3.0) * pi * (radio * radio * radio);

    printf("La superficie del círculo es: %.2f\n", superficie);
    printf("El perímetro del círculo es: %.2f\n", perimetro);
    printf("El volúmen del círculo es: %.2f\n", volumen);

    return 0;
}

