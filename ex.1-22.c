/* 
 * Exercise 1-22. Write a program to "fold" long input lines into two or
 * more shorter lines after the last non-blank character that occurs
 * before the n-th column of input. Make sure your program does
 * something intelligent with very long lines, and if there are no
 * blanks or tabs before the specified column 
 */

 /* Anthony Azzopardi — twanny.azzopardi@gmail.com — 2025-12-01 */

#include <stdio.h>

#define MAXLINE 	1000	/* maximum input line size */
#define FOLDAT		40	/* fold at this position */
#define TABSPACES	4	/* number of spaces for tabs */

int getLine(char line[], int maxline);
void detab(char to[], char from[], int tabspaces);
void strfold(char to[], char from[], int fold);

/* print folded input line */
int main()
{
    int len;			/* current line length */

    char line[MAXLINE];		/* current input line */
    char detabed[MAXLINE];
    char folded[MAXLINE];	/* folded line saved here */

    while ((len = getLine(line, MAXLINE)) > 0){
        detab(detabed, line, TABSPACES);
        strfold(folded, detabed, FOLDAT);
        printf("\n%s", folded);
    }
    return 0;
}

/* strfold: fold 'from' into 'to'; assume to is big enough */
void strfold(char to[], char from[], int fold)
{
    int i,j,k;

    i = j = k = 0;
    while ((from[i]) != '\0'){
	if(((k+1)%fold) == 0){
	   while(1){
	       if((from[i] == ' ')&&(from[i-1] != ' ')){
		   to[j] = '\n';
		   ++j;
		   k = 0;
	           break;
	       }
	       else {
	           --j;
	           --i;
	       }
	   }
	}
	to[j] = from[i];
	++k;
	++j;
        ++i;
    }
    to[j] = '\0';
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

    for (i=0; i<=lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}
