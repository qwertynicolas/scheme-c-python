/* Calcular el factorial de un número ingresado por teclado. El factorial se calcula como el producto de todos
los enteros positivos desde 1 hasta el número. En matemática el factorial se expresa con el símbolo n!. Por
ejemplo, el factorial de 5 es 120 ya que 5! = 1 x 2 x 3 x 4 x 5 =120 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num;
    unsigned long long factorial = 1; //funciona hasta 65

    printf("Ingrese un número: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("No se puede calcular el factorial de números negativos.\n");
    } else {
        for (int i = 1; i <= num; ++i) {
            factorial *= i; // o lo que sería lo mismo factorial = factorial * i
        } 

        printf ("El factorial de %d es %llu.\n", num, factorial);
    }

    return 0;
}