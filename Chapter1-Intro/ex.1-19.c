/* 
 * Exercise 1-19. Write a function reverse(s) that reverses the
 * character string s. Use it to write a program that reverses its input
 * a line at a time. 
 */

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getLine(char line[], int maxline);
void reverse(char to[], char from[], int len);

/* reverses its iput line at a time */
int main()
{
    int len;			/* current line length */
    char line[MAXLINE];		/* current input line */
    char s[MAXLINE];		/* reversed line saved here */

    while ((len = getLine(line, MAXLINE)) > 0){
	reverse(s,line,len);
        printf("%s", s);
    }

    return 0;
}

/* reverse: reverse 'from' into 'to'; assume to is big enough */
void reverse(char s[], char from[], int len)
{
    int i,j;

    i = len-2;
    j = 0;

    s[len]  ='\0';
    s[len-1]='\n';
   
    while (i >= 0){
        s[j] = from[i];
	--i;
        ++j;
    }
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

