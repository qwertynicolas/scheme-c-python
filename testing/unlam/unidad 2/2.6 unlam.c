/*El precio para un vuelo es de $8800 en clase turista y se aplica un incremento del 30% en primera clase.
Se ingresan la cantidad de pasajes vendidos de clase turista y de primera clase.
Obtener la recaudación total del vuelo.*/

#include <stdio.h>
#include <stdlib.h>

int main () {

    int precioTurista = 8800;
    int precioPrimera = (precioTurista * 0.3) + precioTurista;
    int pasajesTurista;
    int pasajesPrimera;
    int recaudacion;

    printf("Ingrese la cantidad de pasajes vendidos de clase turista: ");
    scanf("%d", &pasajesTurista);
    printf("Ingrese la cantida de pasajes vendidos en primera clase: ");
    scanf("%d", &pasajesPrimera);

    recaudacion = (precioTurista * pasajesTurista) + (precioPrimera * pasajesPrimera);

    printf("La recaudación total es: %d\n", recaudacion);
    return 0;



}
