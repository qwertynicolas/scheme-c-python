/* Realizar una función que, dado un mes y un año, calcule la cantidad de días de dicho mes. El año se utilizará 
en  el caso de que  el mes sea febrero  ya que los años bisiestos tienen  29 días  en  lugar  de 28. 
Un año es bisiesto cuando: (el año es divisible por 4 y NO por 100) o (el año es divisible por 400). */

#include <stdio.h>

int bisiesto (int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}
int calcularDia(int mes, int anio);
int main() {

    int mes, anio, dias;

    printf("Ingrese el número del mes: ");
    scanf("%d", &mes);

    if (mes > 12 || mes < 1) {
        printf("No es un valor válido.\n");
        return 1;
    }

    printf("Ingrese el año: ");
    scanf("%d", &anio);

    if (anio < 1 || anio > 9999) {
        printf("No es un valor válido.\n");
        return 1;
    } 

    dias = calcularDia(mes, anio);

    printf("La cantidad de días del mes es: %d\n", dias);

    return 0;
}

int calcularDia(int mes, int anio) {
    int dias;

    // 9, 4, 6, 11 = 30 dias
    // el resto = 31 dias
    // 2 = 28 ó 29 dias

    if (mes == 2) {
        if (bisiesto(anio)) {
            dias = 29;
        } else {
            dias = 28;
        }
    } else if (mes == 9 || mes == 4 || mes == 6 || mes == 11) {
        dias = 30;
    } else {
        dias = 31;
    }

    return dias;
}