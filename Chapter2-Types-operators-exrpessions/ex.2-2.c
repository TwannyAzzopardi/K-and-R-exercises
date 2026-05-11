/*
 *    for (i=0; i<lim-1 && (c=getchar()) != '\n' && != EOF; ++i)
 *        s[i] = c;
 *
 * Exercise 2-2. Write a loop equivalent to the for loop above without
 * using && or ||
 */

#include <stdio.h>

// #define MAXLINE 1000
#define MAXLINE 100

int knr_getline(char s[], int lim);

int main(int argc, char **argv)
{
    char s[MAXLINE];
    int len;

    printf("Exercise 2-2\n\n");
    printf("Enter a line of text, and I will tell you its length: ");              

    len = knr_getline(s, MAXLINE) - 1;
    printf("The line is %d characters long.\n", len);
    printf("The input read is %s\n", s);   
    return 0;
}

/* knr_getline: read a line into s, return length, for Exercises 2-2 */
int knr_getline(char s[], int lim)
{
    int c = 0, i = 0;

    c = getchar();
    
    while (c != '\0'){

        if (i == lim){
            s[i] = c = '\0';
	    ++i;              // because we started counting from 0
	}
        else if (c == EOF)
            s[i] = '\0';
        else if (c == '\n'){
            s[i] = '\n';
	    ++i;
            s[i] = '\0';
	    c = s[i];
        }
        else {
            s[i] = c;
            ++i;
            c = getchar();
        }
    }

    return i;

}

