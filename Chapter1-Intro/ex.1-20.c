/* 
 * Exercise 1-20. Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns. Should n be a
 * variable or a symbolic parameter? 
 */

#include <stdio.h>

#define MAXLINE  	1000	/* maximum input line size */
#define TABSPACES	4	/* number of spaces for tabs */

int getLine(char line[], int maxline);
void detab(char to[], char from[], int tabspaces);

/* print longest input line */
int main()
{
    int len;		/* current line length */
    
    char line[MAXLINE];		/* current input line */
    char notabs[MAXLINE];	/* longest line saved here */

    while ((len = getLine(line, MAXLINE)) > 0){
	detab(notabs,line,TABSPACES);
        printf("%s", notabs);
    }

    return 0;
}

/* detab: replaces tabs in the input with the proper number of blanks */
void detab(char to[], char from[], int tabspaces)
{
    int i, j, k;
    i = j = k = 0;
    
    while(from[i] != '\0'){
        if(from[i] == '\t') {
	    for(k=0; k<tabspaces; ++k){
		to[j+k]=' ';
	    }

            j = j + k;
	    ++i;
	}
	else {
	    to[j] = from[i];
	    ++i;
	    ++j;
        }
    }
   
    to[j] = '\0';
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

