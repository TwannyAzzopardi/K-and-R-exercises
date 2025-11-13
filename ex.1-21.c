//Exercise 1-21. Write a program entab that replaces strings of blanks
//by the minimum number of tabs and blanks to achieve the same spacing.
//Use the same tab stops as for entab. When either a tab or a single
//blank would suffice to reach a tab stop, which should be given
//preference?

#include <stdio.h>

#define MAXLINE  	1000	/* maximum input line size */
#define TABSPACES	4	/* number of spaces for tabs */

int getLine(char line[], int maxline);
void entab(char to[], char from[], int tabspaces);

int main()
{
    int len;		/* current line length */
    
    char line[MAXLINE];		/* current input line */
    char tabs[MAXLINE];	/* longest line saved here */

    while ((len = getLine(line, MAXLINE)) > 0){
	    entab(tabs,line,TABSPACES);
        printf("%s", tabs);
    }

    return 0;
}

/* entab: replaces tabs in the input with the proper number of blanks */
void entab(char to[], char from[], int tabspaces)
{
    int i, j, k, c, tabs, spaces, pos;
    i = j = k = c = 0;

    while(from[i] != '\0'){
	if((from[i] == ' ' && from[i+1] == ' ') || (from[i] == ' ' && from[i+1] != ' ') ){
	    to[j] = ' ';
	    ++i;
	    ++j;
	    ++c;
	}
	else{
	    /* insert tab and spaces from here */
	    if(c>tabspaces){
		pos = j - c;
		tabs = c / tabspaces;
		spaces = c - ( tabs * tabspaces );
		for(k=pos; k<(pos+tabs); ++k)
		    to[k] = '\t';
		pos = k;
		for(k=pos; k<pos+spaces; ++k)
		    to[k]=' ';
		j=k;
		c=0;
	    }

	    to[j] = from[i];
	    ++i;
	    ++j;
	}
    }
    to[j]='\0';
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
