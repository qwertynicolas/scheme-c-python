/* Realizar un programa que ingrese la fecha actual y la fecha de nacimiento de una persona y calcule su edad. 
Para validar las fechas utilizar la función del punto 9. Para el cálculo realizar una función que reciba las dos 
fechas y retorne la edad de la persona */

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

int calcularEdad (int dia, int mes, int anio, int dia_nacimiento, int mes_nacimiento, int anio_nacimiento) {
    int edad; 

    edad = anio - anio_nacimiento;

    if (mes < mes_nacimiento || (mes == mes_nacimiento && dia < dia_nacimiento)) {
        --edad;
    }

    return edad;
}

int main() {
    int dia, mes, anio, dia_nacimiento, mes_nacimiento, anio_nacimiento;
    int edad;

    printf("Ingrese la fecha actual: ");
    scanf("%d %d %d", &dia, &mes, &anio);

    if (!recibirFecha(dia, mes, anio)) {
        printf("No es una fecha válida.\n");
        return 1;
    }

    printf("Ingrese la fecha de nacimiento: ");
    scanf("%d %d %d", &dia_nacimiento, &mes_nacimiento, &anio_nacimiento);

    if (!recibirFecha(dia_nacimiento, mes_nacimiento, anio_nacimiento)) {
        printf("La fecha de nacimiento NO es válida.\n");
        return 1;
    }

    edad = calcularEdad(dia, mes, anio, dia_nacimiento, mes_nacimiento, anio_nacimiento);
    printf("Edad actual de la persona: %d años.\n", edad);

    return 0;
}

