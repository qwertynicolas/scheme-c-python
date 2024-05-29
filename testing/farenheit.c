#include <stdio.h>

main() 
{
    /* print Celsius-Farenheit table
    for celsius = -17.8, 60.0, ... , 148.9 */
    printf("Celsius\t\tFarenheit\n");
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table*/
    upper = 300;    /* upper limit */
    step = 20;      /* steep size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%6.1f\t\t%3.0f\n", celsius, fahr);
        fahr = fahr + step;

    }
    return 0;

}