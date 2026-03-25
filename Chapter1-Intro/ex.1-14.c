/* 
 * Exercise 1-14.  Write a program to print a histogram of the
 * frequencies of different characters in its input. 
 */

#include <stdio.h>

int main()
{
    int c, i, j;                        
    int freq[130];

    for(i = 0; i < 130; ++i)
        freq[i] = 0;

    while((c = getchar()) != EOF)
        ++freq[c];
    
    for(i = 0; i < 130; ++i){
        if(freq[i] != 0){
            if(i == 9){
                printf("\\t\t",i);
                for(j=0;j<freq[i];++j)
                       printf("*");
                printf("\n");
            }
            else if (i == 10){
                printf("\\n\t",i);
                for(j=0;j<freq[i];++j)
                       printf("*");
                printf("\n");
            }
            else if (i == 32){
                printf("space\t");
                for(j=0;j<freq[i];++j)
                       printf("*");
                printf("\n");
            }
            else{
                printf("%c\t",i);
                for(j=0;j<freq[i];++j)
                       printf("*");
                printf("\n");
            }
        }
    }
}
