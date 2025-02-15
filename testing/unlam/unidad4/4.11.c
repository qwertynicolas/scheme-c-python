#include <stdio.h>
#include <stdlib.h>

/* 31 días:
 *enero
 *marzo
 *mayo
 *julio
 *agosto
 *octubre
 *diciembre
 **/

int main (void)
{
    int year, month;
    int bisiesto = 0;

    printf("Ingrese el año: ");
    scanf("%d", &year);

    if ((year % 4 == 0) && (year % 100 != 0)) {
        bisiesto = 1;
    }

    printf("Ingrese el número del mes: ");
    scanf("%d", &month);

    if ((bisiesto == 1) && (month == 2)) {
        printf("El mes tiene 29 días.");
        return 0;
    }

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("El mes tiene 31 días.");
            break;
        case 2:
            printf("El mes tiene 28 días.");
            break;
        default:
            printf("El mes tiene 30 días.");
    }

    return 0;

}
