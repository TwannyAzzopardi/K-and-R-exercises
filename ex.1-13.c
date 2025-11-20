/* 
 * Exercise 1-13. Write a program to print a histogram of the lengths of
 * words in its input.  It is easy to draw the histogram with the bars
 * horizontal; a vertical orientation is more challenging. 
 */

#include <stdio.h>

#define	IN	1	/* inside a word */
#define OUT	0	/* outside a word */

int main()
{
    int c, state, fw, wl, x;
    state = OUT;
    fw = wl = 0;

    while(( c = getchar()) != EOF){
	if (c == ' ' || c == '\n' || c == '\t'){
	    state = OUT;
	    if(wl !=0){
	        for (x = 1; x <= wl; x++)
		    if(x == 1){
		        printf("\t\t\t\t\t\t\t\t");
	                printf("*");
		    }
		    else
	                printf("*");
	        wl = 0;
	    }
        }
	else if (state == OUT){
	    state = IN;

	    /* if first word, do not print newline */
	    if (fw == 0)
		fw = 1;
            else  
	        printf("\n");
	}
        if (state == IN){
	    putchar(c);
            /* count the number of characters in the word, here? */
            ++wl;
        }
    }
}
