#include <stdio.h>

int main() {
    int c;
    int prev = 0; // variable used to stored the previous character

    while ( (c= getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else {
            if (prev != ' ') {
                putchar(c);
            }
        }
        prev = c;  // update the previous character
    }
    return 0;
}