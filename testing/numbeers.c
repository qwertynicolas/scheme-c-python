#include <stdio.h>
#include <stdlib.h>

int main() {

    int luckyNumber[] = {7, 6, 12, 86, 53, 83, 96};

    printf("%d\n", luckyNumber[0]); 
    printf("%d\n", luckyNumber[1]);
    printf("%d\n", luckyNumber[2]);
    printf("%d\n", luckyNumber[3]);
    luckyNumber[4] = 23;
    printf("%d\n", luckyNumber[4]);
    printf("%d\n", luckyNumber[5]);
    printf("%d\n", luckyNumber[6]);

    return 0;
}
