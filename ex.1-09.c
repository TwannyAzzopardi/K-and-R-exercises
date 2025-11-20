/* 
 * Exercise 1-9.  Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.  
 */

#include <stdio.h>

main()
{
    int c, blank;

    while((c = getchar()) != EOF){
         if(c != ' '){
	     putchar(c);
	     blank = 0;
	     }

	 else if(blank == 0){
	     putchar(c);
	     ++blank;
	     }
     }
}

