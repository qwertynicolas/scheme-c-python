/* En  un  proceso  de  control  se  evalúan  valores  de  temperatura,  finalizando  cuando  de  ingresa  un  valor 
ficticio de temperatura -50. Determinar el valor máximo y mínimo medido y sus posiciones respecto al ingreso. */

#include <stdio.h>

int main() {

    float temp;
    float minimo = 199999.00;
    float maximo = -40.00;
    int posicion = 0;
    int posicion_minimo;
    int posicion_maximo;

    while (1) {

        printf("Ingrese un valor de temperatura (-50 para finalizar): ");
        scanf("%f", &temp);

        if (temp == -50) {
            break;
        } else {
            ++posicion;
        }

        if (temp < minimo) {
            minimo = temp;
            posicion_minimo = posicion;
        }  

        if (temp > maximo) {
            maximo = temp;
            posicion_maximo = posicion;
        }


    }
        if (posicion > 0) {    
        printf("El valor máximo de temperatura fue: %.2f. Posicion: %d\n", maximo, posicion_maximo);
        printf("El valor mínimo de temperatura fue: %.2f. Posicion: %d\n", minimo, posicion_minimo);
        } else {
            printf("No se ingresaron valores.\n");
        }
    return 0; 
}