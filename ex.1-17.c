/* 
 * Exercise 1-17. Write a program to print all input lines that are
 * longer than 80 characters. 
 */

#include <stdio.h>
#define MAXLINE 100 	/* maximum input line size */

int getLine(char line[], int maxline);

int main()
{
    int len;		/* current line length */
    int c;		/* inserted by twanny for debugging */
    printf("----------------------------------------------------------------------------------------------------\n");

    char line[MAXLINE];		/* current input line */

    while ((len = getLine(line, MAXLINE)) > 0){
	/* Test for long input line */
	if (len == MAXLINE - 1 && line[MAXLINE -2] != '\n'){
	    while ((c=getchar()) != '\n')
		++len;
	    ++len;	/* to include the newline character */
	}
	if (len >= 80)
	    printf("%s\n",line);
    }
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

