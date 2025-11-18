/* To illustrate the use of character arrays and functions to manipulate
 * them, let's write a program that reads a set of text lines and prints
 * the longest.*/

/* Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and as
 * much as possible of the text.*/

#include <stdio.h>
#define MAXLINE 80  	 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len,nc;		/* current line length */
    int max;		/* maximum length seen so far */
    char line[MAXLINE];		/* current input line */
    char longest[MAXLINE];	/* longest line saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0){
	if(line[len-1] != '\n'){
    	    // keep counting line up to '\n'
	    nc=len;
            while(getchar() != '\n') 
	        ++nc;    
            if(nc > max){
	       max = nc;
	       copy(longest, line);
	    }

            printf("%d   %s\n", nc, line);
        }
    }
    printf("\nThe longest of the 'longer than buffer' lines is:");
    printf("\n%s\n", longest);
    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
