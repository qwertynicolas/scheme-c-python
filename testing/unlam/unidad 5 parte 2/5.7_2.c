/* Ingresar diversos quintetos de números positivos de 1 cifra c/u, finalizando cuando las cinco cifras leídas
sean iguales a cero. Determinar e informar cuantos de los quintetos ingresados han formado números
capicúas 'triples' y cuantos 'quíntuples */

#include <stdio.h>
#include <stdlib.h>

int main() { // ejemplo de capicua triple 232, capicua quintuple 23332

    int ceros = 0;
    int num1, num2, num3, num4, num5; 
    int capicuas_triple = 0;
    int capicuas_quintuples = 0;

    do {
    
    printf("Ingrese el primer número (0 para finalizar): ");
    scanf("%d", &num1);
    
    if (num1 == 0) {
      ++ceros;
    }

    printf("Ingrese el segundo número (0 para finalizar): ");
    scanf("%d", &num2);

    if (num2 == 0) {
      ++ceros;
    }

    printf("Ingrese el tercer número (0 para finalizar): ");
    scanf("%d", &num3);

    if (num3 == 0) {
      ++ceros;
    }

    printf("Ingrese el cuarto número (0 para finalizar): ");
    scanf("%d", &num4);

    if (num4 == 0) {
      ++ceros;
    }

    printf("Ingrese el quinto número (0 para finalizar): ");
    scanf("%d", &num5);
    
    printf("\n");

    if (num5 == 0) {
      ++ceros;
    }

    if (ceros == 5) {
      break;
    }

    if (num1 == num3) {
      ++capicuas_triple;
    } 

    if (num1 == num5 && num2 == num3 && num2 == num4 && num3 == num4) {
      ++capicuas_quintuples;
    }

  } while (ceros != 5);

    printf("\n");
    printf("Hubo %d capicúas triples.\n", capicuas_triple);
    printf("Hubo %d capicúas quintuples.\n", capicuas_quintuples);

    return 0;
}
