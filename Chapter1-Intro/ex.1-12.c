/* 
 * Exercise 1-12. Write a program that prints its input one word per
 * line. 
 */ 

#include <stdio.h>

#define	IN	1	/* inside a word */
#define OUT	0	/* outside a word */

int main()
{
    int c, nl, nw, nc, state, fw;
    state = OUT;
    fw = 0;

    while(( c = getchar()) != EOF){
	if (c == ' ' || c == '\n' || c == '\t')
	    state = OUT;
	else if (state == OUT){
	    state = IN;

	    /* if first word, do not print newline */
	    if (fw == 0)
		fw = 1;
            else  
	        printf("\n");
	}
        if (state == IN)
	    putchar(c);
    }
}
