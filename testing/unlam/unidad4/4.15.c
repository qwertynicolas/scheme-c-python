#include <stdio.h>
#include <stdlib.h>

int main (void)
{
   int dvds, dvdsAyuda;
   float precioFinal = 0.0;

   printf("Ingrese la cantidad de DVDs a comprar: ");
   scanf("%d", &dvds);

   dvdsAyuda = dvds;

   if (dvds < 1 || dvds > 500) {
       printf("La cantidad no es válida.");
       return 0;
   }

   if (dvds > 50) {
       int mult50 = dvds / 50;
       dvds -= mult50 * 50;
       precioFinal += mult50 * 500;
   }

   if (dvds > 10 && dvds < 50) {
       int mult10 = dvds / 10;
       dvds -= mult10 * 10;
       precioFinal += mult10 * 120;
   }

   if (dvds > 1 && dvds < 9) {
       precioFinal += dvds * 15;
       dvds = 0;
   }

   if (dvdsAyuda > 100) {
       precioFinal *= 0.9;
   }

   if (dvds == 0) {
       printf("El precio total es: $%.2f", precioFinal);
   } else {
       printf("La cantidad no es válida.");
   }

   return 0;
}
