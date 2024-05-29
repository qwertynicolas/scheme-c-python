#include <stdio.h>

int main() {
    int c;
    int tab = 0, blanks = 0, nl = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if ( c == '\t') {
            tab++;
        } else if ( c == '\n') {
            nl++;
        }
    }
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tab);
    printf("New lines: %d\n", nl);
    
    return 0;
}