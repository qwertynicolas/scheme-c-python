
#include <stdio.h>
#include <unistd.h>

int main () {

    while (1) {
        printf("Trabajando... Presione CTRL + C para interrumpir.\n");
        sleep (2);
    }
    
    return 0;
}