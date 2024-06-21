
#include <stdio.h>
#include <stdlib.h>

double cube(double num) {

    return num * num * num;
}

int main() {

    printf("Answer: %.3f\n", cube(7.5));
    return 0;
}
