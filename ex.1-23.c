/* 
 * Exercise 1-23. Write a program to remove all comments from a C
 * program. Don't forget to handle quoted strings and character
 * constants properly. C comments do not nest.
 */

/* Anthony Azzopardi — twanny.azzopardi@gmail.com — 2025-12-05 */

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int incomment = 0;

int getLine(char line[], int maxline);
void remComments(char to[], char from[]);

int main()
{

    int len;		/* current line length */
    char line[MAXLINE];		/* current input line */
    char noComments[MAXLINE];	/* noComments line saved here */


    while ((len = getLine(line, MAXLINE)) > 0){
        remComments(noComments, line);
        printf("%s", noComments);
    }
    return 0;
}

/* remComments: Remove line comments from 'from' and copy the  'to' */
void remComments(char to[], char from[])
{
    extern int incomment;

    int i;
    i =  0;

    while ((from[i]) != '\0'){
	while(1){
            if((from[i] == '/')&&(from[i+1]=='*')){
	        to[i] = ' ';
	        ++i;
	        to[i] = ' ';
	        ++i;
	        incomment = 1;
	        break;
	    }  
            if((from[i] == '*')&&(from[i+1]=='/')){
	        to[i] = ' ';
	        ++i;
	        to[i] = ' ';
	        ++i;
	        if(from[i] == '\n'){
		   to[i] = '\n';
		   ++i;
		   incomment = 0;
		   break;
		}
	        incomment = 0;
	        break;
	    }   
            if(incomment==1){
		if(from[i]=='\n'){
		   to[i]='\n';
		   ++i;
		   break;
		}
		else {
	           to[i] = ' ';
	           ++i;
	           break;
	        }
	    } 
            if(incomment==0){
	        to[i] = from[i];
		++i;
	        break;
	    }   
       }
    }
    to[i] = '\0';
    i = 0;
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
