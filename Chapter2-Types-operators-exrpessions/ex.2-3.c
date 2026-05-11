/*
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its
 * equivalent integer value. The allowable digits are 0 through 9, a
 * through f, and A through F.
 */

#include <stdio.h>
#define MAXLINE 1000

int knr_getline(char s[], int lim);
int power(int base, int n);
int lower(int c);
int htoi(char s[], int len);

int main()
{
    char s[MAXLINE];

    while(1)
    {
	    int i,c;
	    int input_not_ok = 0;

	    printf("Please enter hex number: ");
	    knr_getline(s, MAXLINE);
	    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
                s[1] = '0';
            
	    for (i=0; s[i] != '\n'; i++){
                if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') ) {
                    c = s[i];
		    s[i] = lower(c);
		}    
	        else {
		    input_not_ok = 1;
                    break;	
                }

            }
	    if (input_not_ok == 0){
                printf("You entered %s, which is %d characters long.\n",s,i);
	        printf("The decimal equivalent is %d.\n",htoi(s,i));
            }
            else
	        printf("Input characters entered are not allowed\n");
    }
}



/* knr_getline: read a line into s, return length */
int knr_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c !='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

/* htoi: converts a hex string into it's decimal equivalent */
int htoi(char s[], int len)
{
  int decimal , j, c;
  decimal = j = 0;

  for (int i=len; i >= 0; --i){
      if ((s[i] >= 'a' && s[i] <= 'f')) {
         c = s[i]; 
	 c -= 87;
         decimal += c * power(16, j++); 
      } 
      if ((s[i] >= '0' && s[i] <= '9')) {
         c = s[i]; 
	 c -= 48;
         decimal += c * power(16, j++); 
      } 

  }
  return decimal;
}

