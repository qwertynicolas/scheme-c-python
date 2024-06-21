/*Confeccionar un programa que ingrese una medida en ‘pies’ y la exhiba convertida a yardas, pulgadas, cms.
y mts. NOTA: 1 pie = 12 pulgadas; 1 yarda = 3 pies; 1 pulgada = 2,54 cms.*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int pies;
    float pulgadas;
    float yardas;
    float cms;
    float mts;

    printf("Ingrese una medida en pies: ");
    scanf("%d", &pies);
    getchar();

    pulgadas = 12 * pies;
    yardas = pies / 3.0;
    cms = pulgadas * 2.54;
    mts = cms / 100;

    printf("La medida en yardas es: %.2f\n", yardas);
    printf("La medida en pulgadas es: %.2f\n", pulgadas);
    printf("La medida en centímetros es: %.2f\n", cms);
    printf("La medida en metros es: %.2f\n", mts);
    
    return 0;

}
