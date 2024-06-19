//calculator

#include <stdio.h>
#include <stdlib.h>

int main() {

    double num1, num2, result;
    char operator;

    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter an operator: ");
    scanf(" %c", &operator);
    printf("Enter a number: ");
    scanf("%lf", &num2);

    if (operator == '+') {
        result = num1 + num2;
    } else if (operator == '-') {
        result = num1 - num2;
    } else if (operator == '/') {
        result = num1 / num2;
    } else if (operator == '*') {
        result = num1 * num2;
    } else {
        printf("Invalid operator. Make sure to use one of the following: /, +, -, *\n");
        return 1;
    }

    printf("The result is: %.1f\n", result);

    return 0;
}