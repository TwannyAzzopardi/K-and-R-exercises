/* 
 * Exercise 1-4. Write a program to print the corresponding Celsius to
 * Fahrenheit table. F = ( 9/5 X C ) + 32 
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ..., 300; floating-point version */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;		/* lower limit of temperature table */
    upper = 300;	/* upper limit */
    step = 20;		/* step size */

    /* printf("01234567890123456789\n"); */
    printf("Celsius\tFahrenheit\n\n");    

    celsius = lower;
    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + 32;
	printf("%3.0f\t%6.1f\n", celsius, fahr);
	celsius = celsius + step;
    }
}
