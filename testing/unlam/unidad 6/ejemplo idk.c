#include <stdio.h>
#include <stdlib.h>

int areaOfRect(int lenght, int width) {// debería de ser double tanto el valor de la función como el de los parámetros puesto que se puede tomar valores con puntos decimales

    int area;

    area = lenght * width;

    return area; 
}

int main() {

    int area; // esto, como en el caso anterior, debería de ser double o float (preferenteme double para mayor precisión)

    do { // el lenght y width lo declaro en ciclo do, puesto que la estructura principal del programa va a ser infinita hasta que se ingresen datos válidos o -1

        int lenght;
        int width;

        printf("Ingrese el valor de largo del rectángulo. -1 para finalizar: ");
        scanf("%d", &lenght);
        if (lenght == -1) {
            break;
        }
        printf("Ingres el valor de ancho del rectángulo. -1 para finalizar: ");
        scanf("%d", &width);
        if (width == -1) {
            break;
        }

        area = areaOfRect(lenght, width);

        if (area > 0) {
            printf("Área del rectángulo: %d\n", area);
        } else {
            printf("Números inválidos. Intente de nuevo.\n");
            continue;
        }
   
    } while (area == 0); // esta condición es visible gracias al else final en la estructura del do, de no estar, el usuario no tendría forma de saber que ingreso datos inválidos.

    return 0;
}