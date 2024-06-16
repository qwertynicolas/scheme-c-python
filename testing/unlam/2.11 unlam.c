/* Una pizzería vende empanadas por unidad o por docena, la docena cuesta $300 pero si se compra
individualmente se cobra $30 la unidad. Si se compran más empanadas que no se agrupen en docenas las
adicionales se cobran como por unidad. Indicar el precio total a abonar.*/

#include <stdio.h>
#include <stdio.h>

int main() {

    const int precio_docena = 300;
    const int precio_unidad = 30;
    int empanadas, docenas, unidades, precio_total;

    printf("Ingrese la cantidad de empanadas que desea comprar: ");
    scanf("%d", &empanadas);

    docenas = empanadas / 12;
    unidades = empanadas % 12;

    precio_total = (docenas * precio_docena) + (unidades * precio_unidad);

    printf("El precio total a abonar será de: %d\n", precio_total);

    return 0;
}

