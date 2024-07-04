/* Confeccionar  un  programa  que  permita  determinar  e  informar  en  cuántos  de  los  números  enteros 
comprendidos entre 10001 y 90009 existen más  cifras 3 que 4. Debe existir por lo menos, un 4 para que 
sea  considerado  el  número  como  válido.  Para  resolverlo  confeccionar  una  función  llamada  CIFRAS,  que 
pueda determinar cuántas cifras “n” existen en un número de 5 cifras. */

#include <stdio.h>


int contar_cifras(int numero, int n) {

    int contador = 0;
    while (numero > 0) {
        if (numero % 10 == n) {
            contador++;
        }
        numero /= 10;
    }

    return contador;
}

int CIFRAS (int lim_inferior, int lim_superior) {
    int contador = 0;

    for (int i = lim_inferior; i <= lim_superior; ++i) {
        if (contar_cifras(i,4) > 0) {
            int cifras3 = contar_cifras(i, 3);
            int cifras4 = contar_cifras(i, 4);

            if (cifras3 > cifras4) {
                contador++;
            } 
        }
    }

    return contador;

}

int main() {
    int lim_inferior = 10001;
    int lim_superior = 90009;

    int resultado = CIFRAS(lim_inferior, lim_superior);

    printf("Cantidad de numeros válidos: %d\n", resultado);

    return 0;
}