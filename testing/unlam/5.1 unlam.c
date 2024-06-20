// Mostrar por pantalla los números pares comprendidos entre 100 y 500.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;

        for (i = 100; i <= 500; ++i) {
        if (i % 2 == 0) {
        printf("%d\n", i);
    }  
    }

    return 0;
}