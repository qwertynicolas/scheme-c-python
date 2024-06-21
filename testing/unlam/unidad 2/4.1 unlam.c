/* Se ingresan 3 números distintos. Determinar el mayor. */

#include <stdio.h>
#include <stdlib.h>

int main() {

     int n1, n2, n3;

     printf("Ingrese el primer número: ");
     scanf("%d", &n1);
     printf("Ingrese el segundo número: ");
     scanf("%d", &n2);
     printf("Ingrese el tercer número: ");
     scanf("%d", &n3);

     if (n1 > n2 && n1 > n3) {
        printf ("El mayor es: %d\n", n1);
     }  else if (n2 > n1 && n2 > n3) {
        printf ("El mayor es: %d\n", n2);
     } else {
        printf("El mayor es %d\n", n3);
     }
        
    return 0;
}
