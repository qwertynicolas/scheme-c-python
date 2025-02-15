#include <stdio.h>

int main (void)
{
   char w;
   int nums, otros, letrasMayus, letrasMinus;

   nums = letrasMayus = letrasMinus = otros = 0;

   do {
       printf("Ingrese un carácter (* para finalizar): ");
       w = getchar();

       while (getchar() != '\n');

       if (w >= 'a' && w <= 'z') {
           ++letrasMinus;
       } else if (w >= 'A' && w <= 'Z') {
           ++letrasMayus;
       } else if (w >= '0' && w <= '9') {
           ++nums;
       } else {
           ++otros;
       }

       /* fflush(stdin); */

   } while (w != '*');

   printf("Números: %d\n", nums);
   printf("Letras mayúsculas: %d\n", letrasMayus);
   printf("Letras minúsculas: %d\n", letrasMinus);
   printf("Otros: %d", otros);

   return 0;
}
