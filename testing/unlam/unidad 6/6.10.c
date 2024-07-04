/* Realizar una función que permita sumar 1 día a una fecha válida mostrando la fecha resultante. Si la fecha 
recibida no es válida informarlo con un mensaje (validar utilizando la función del punto 9).*/

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

int main() {
    int dia, mes, anio;

    printf("¿A qué fecha desea agregarle un día?: ");
    scanf("%d %d %d", &dia, &mes, &anio);

    if (recibirFecha(dia, mes, anio)) {
        dia += 1;
        if (recibirFecha(dia, mes, anio)) {
            printf("La nueva fecha es %d/%d/%d.\n", dia, mes, anio);
        } else {
            printf("La fecha NO es válida.\n");
        }
    }

    return 0;
}