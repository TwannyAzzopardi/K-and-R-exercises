/* Exercise 1-7. Write a program to print the value of EOF. */

#include <stdio.h>

/* copy input to output; 2nd version */
int main()
{
    int c;

    while(1){ 
        if ((c = getchar()) != EOF)
            putchar(c);
        else{
	    printf("\nThis is end of file %d\n", c);
	    break;
	}
    }
}
