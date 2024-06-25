#include <stdio.h>

int power(int m, int n); // the names of the parameters are not really needed, we could've written int, int, since this is only the prototype of power, and not power itself

int main() {

    int i;
    for (i = 0; i < 10; ++i) 
        printf("%d %d %d\n", i, power(2, i), power(3, i)); // here the call to power returns the value of p, which is the result of p * base, for example, 512, 19683, while i is established in the for loop and can only take values up to 9, which is also the max exponent n can be elevated to
    
    return 0;
}

int power(int base, int n) /* raise base to the n-th power; n >=0 */
{

    int i, p;

    p = 1;

    for (i = 1; i <= n; ++i) // the value of n is asigned in main when calling to function, which, in this case, is i, that is in a loop from 0 to 9
        p = p * base; // the same happens with the value of base, its value it's given in main when calling the function, in this case, 2 and 3 are the values

    return p; // this is the value that power returns, in this case, power(2, i) and power(3, i) will take the value of p, each with different values
}