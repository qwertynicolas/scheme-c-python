/*Conociendo la cantidad de tarros de pintura que existe en un depósito de una pinturería y sabiendo que el
50% son tarros de 1Lt, el 30% tarros de 4Lts. y el resto tarros de 20Lts. Determinar la cantidad de tarros de
1Lt., 4Lts. Y 20 Lts*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int tarros, t1, t4, t20;

    printf("Ingrese la cantidad de tarros del depósito: ");
    scanf("%d", &tarros);

    t1 = tarros * 0.5;
    t4 = tarros * 0.3;
    t20 = tarros * 0.2;

    printf("La cantidade tarros de 1 litro son: %d\n", t1);
    printf("La cantidad de tarros de 4 litros son: %d\n", t4);
    printf("La cantidad de tarros de 20 litros son: %d\n", t20);

    return 0; 
}
