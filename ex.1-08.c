/* 
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main()
{
    int c, b, t, nl;

    b = t = nl = 0;

    while(( c = getchar()) != EOF){
        if (c == ' ')
	    ++b;
	else if (c == '\t')
	    ++t;
	else if (c == '\n')
	    ++nl;
	}
    
    printf("Number of blanks is %d.\n",b);
    printf("Number of tabs   is %d.\n",t);
    printf("Number of lines  is %d.\n",nl);

}
