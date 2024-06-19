/* Ejemplo 1: Confeccionar un programa que solicite el medio de transporte para llegar desde La Plata
hasta la UNLaM. Mostrando en pantalla el tiempo estimado de viaje para cada medio de transporte.
El medio de transporte se ingresa con una letra siendo:
 T: tren, tiempo estimado de viaje 90 min.
 C: colectivo, tiempo estimado de viaje 180min 
 A: auto, tiempo estimado de viaje, 90 min.
 H: helicóptero, tiempo estimado de viaje, 20 min. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    char transporte;

    printf("Ingrese el medio de transporte para ir desde La Plata hasta la UNLaM: ");
    scanf("%c", &transporte);

    switch (transporte) {
        case 'T' :
        case 'A' : printf("Tiempo estimado de viaje: 90 minutos.\n");
        break;
        case 'C' : printf("Tiempo estimado de viaje: 180 minutos.\n");
        break;
        case 'H' : printf("Tiempo estimado de viaje: 20 minutos.\n");
        break;
        default : printf("Medio de transporte inválido.\n");

}
    return 0;
}
