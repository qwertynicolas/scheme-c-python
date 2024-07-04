/* Realizar una función que reciba 3 números enteros correspondientes al día, mes y año de una fecha y valide 
si  la  misma  es  correcta.  En  caso  de  que  la  fecha  es  correcta  debe  retornar  un  1  y  si  es  incorrecta  debe 
retornar un 0. Para la validación usar la función del punto 8 que retorna la cantidad de días de un mes.  */

#include <stdio.h>

int bisiesto (int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
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

int recibirFecha (int dia, int mes, int anio);
int main() {

    int dia, mes, anio;

    printf("Ingrese el día: ");
    scanf("%d", &dia);
    
    printf("Ingrese el mes: ");
    scanf("%d", &mes);
    
    printf("Ingrese el año: ");
    scanf("%d", &anio);

    if (recibirFecha(dia, mes, anio)) {
        printf("La fecha es válida.\n");
    } else {
        printf("La fecha NO es válida.\n");
    }

    return 0;
}

int recibirFecha(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12) {
        return 0;
    }

    if (anio < 1) {
        return 0;
    }

    int dias_en_mes = calcularDia(mes, anio);

    if (dia < 1 || dia > dias_en_mes) { // 28, 29, 30, 31
        return 0;
    }

    return 1;

}