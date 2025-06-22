#include <stdio.h>

int main(void)
{

    /* int *ip; */

    /* ip = &x; // here I'm assigning the memory address of the variable x to the pointer ip, so ip now points to x */

    /* printf("Memory address of x: %p", &x); */
    /* printf("\nMemory address of ip: %p", &ip); */
    /* printf("\nContents of x: %d", x); */
    /* printf("\nContents of ip: %d\n", *ip); */


    /* y = *ip; // and here I'm assigning the contents of the pointer ip to the variable y */
    /*          // */
    /*          // & = gets the address of a variable */
    /*          // * = access the contents at the stored address, in the previous case ip was holding the memory address of x, and x */
    /*          // was holding 1 at its contents */

    /* *ip = 0; */

    /* z[4] = y; */
    /* ip = &z[0]; */


    int x;
    int *px;

    px = &x;
    *px = 10;

    printf("%d\n", x);

    return 0;
}
