#include <conio.h>
#include <stdio.h>

int main () {
        int salario, salario_mensual;
        printf("Introduzca su salario por hora: ");
        scanf("%d\n", &salario)

        salario_mensual = salario * 8;

        printf("Su salario mensual es: %d\n", salario_mensual);
        return 0;
}
