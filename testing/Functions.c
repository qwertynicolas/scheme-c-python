#include <stdlib.h>
#include <stdio.h>

int main() {

    printf("Top\n");
    ddd("Tony Montana", 35);
    ddd("Tommy", 29);
    ddd("Vito Corleone", 65);
    printf("Bottom\n");

    return 0;

}

void ddd(char name[], int age) {

    printf("Hello %s, your age is %d\n", name, age);
    
}
