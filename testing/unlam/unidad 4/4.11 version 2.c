//forma secundaria (y mejor) de realizar el 4.11. usando switch y sabiendo que mes tiene 30 días y cual 31

#include <stdio.h>
#include <stdlib.h>

int main() {

    int anio, mes;
    int dias;

    printf("Ingrese el año: ");
    scanf("%d", &anio);
    printf("Ingrese el número del mes: ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) {
        printf("Número de mes no válido.\n");
        return 1;
    }

    int bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);

    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dias = 31;
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        case 2:
            dias = bisiesto ? 29 : 28;
            break;
    }

    printf("El mes tiene %d días.\n", dias);

    return 0;
}
