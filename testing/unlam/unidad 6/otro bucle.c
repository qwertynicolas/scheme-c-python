#include <stdio.h>

int main() {
    int c;
    printf("Ingrese texto (Ctrl+D para finalizar):\n");
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    printf("\nFin de entrada detectado.\n");
    return 0;
}
