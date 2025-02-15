#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int pies;

    printf("Ingrese una medida en pies: ");
    scanf("%d", &pies);

   int pulgadas = 12 * pies;
   float yarda = (float)pies / 3;
   float cms = (float)2.54 * pulgadas;

   printf("En pulgadas: %d\n", pulgadas);
   printf("En yardas: %.2f\n", yarda);
   printf("En centímetros: %.2f\n", cms);

   return 0;
}
