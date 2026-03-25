/* 
 * Exercise 1-18 : Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely blank lines. 
 */  

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getLine(char line[], int maxline);

int main()
{
    int len,i,eot;		/* current line length */
    char line[MAXLINE];		/* current input line  */

    while ((len = getLine(line, MAXLINE)) > 0){
	i = len-1;
	while(i != -1){
	    if(line[i]==' ' || line[i]=='\n' || line[i]=='\t')
		--i;
	    else{
		eot = i;
		line[i+1]='\n';
		line[i+2]='\0';
		i = -1;
	    }
	}
	if(eot >= 0){
            printf("%d\t%s", eot,line);
	    eot = 0;
	}
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
