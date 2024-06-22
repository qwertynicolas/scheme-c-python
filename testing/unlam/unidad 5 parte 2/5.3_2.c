/* Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite un *. Se
desea obtener e informar cuantos caracteres ingresados son numéricos y cuantos alfabéticos. Estos últimos
tienen que mostrarse separados por mayúsculas y minúsculas. También informar la cantidad de otros
símbolos que no sean ni letras ni números */


#include <stdio.h>
#include <stdlib.h>

int main() { // ejercicio idéntico a los que están en el libro de dennis ritchie, en su caso se usa el getchar y putchar para hacer esto

    int nums = 0;
    int minuscula = 0;
    int mayuscula = 0;
    int otros = 0;
    char input;

    printf("Ingrese caracteres, para finalizar ingrese un '*' : ");

    while (1) {
        input = getchar();

        if (input == '*') {
            break;
        }

        if (input >= '0' && input <= '9') {
            ++nums;
        }

        if (input >= 'a' && input <= 'z') {
            ++minuscula;
        }

        if (input >= 'A' && input <= 'Z') {
            ++mayuscula;
        } else {
            ++otros;
        }
    }

    printf("%d letras minúsculas.\n", minuscula);
    printf("%d letras mayúsculas.\n", mayuscula);
    printf("%d valores numéricos.\n", nums);
    printf("%d símbolos.\n", otros);

    return 0;
}