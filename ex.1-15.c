/* 
 * Exercise 1-15. Rewrite the tempreature conversion program of Section
 * 1.2 to use a function for conversion.
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int fah2cel( int );

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;		/* lower limit of temperature table */
    upper = 300;	/* upper limit */
    step = 20;		/* step size */

    fahr = lower;

    printf("\n\n\nFahrenheit-Ceslsius table.\n");

    while (fahr <= upper) {
	printf("%d\t%d\n", fahr, fah2cel(fahr));
	fahr = fahr + step;
    }
}

int fah2cel( int fahr )
{
    int celsius;

    celsius = 5 * (fahr-32) / 9;
    
    return celsius;
}
