/*Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide transformarlo a un
número con formato (aammdd).*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int dia, mes, anio;
    int fecha;
    int nueva_fecha;

    printf("Ingrese un número entero que represente una fecha en formato dd/mm/aa: ");
    scanf("%d", &fecha);

    dia = fecha / 10000;
    mes = (fecha / 100) % 100;
    anio = fecha % 100;

    nueva_fecha = anio * 10000 + mes * 100 + dia;

    printf("La fecha en formato aammdd es: %06d\n", nueva_fecha);
    return 0;

}