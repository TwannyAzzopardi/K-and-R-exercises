/*
 * Exercise 2-1. Write a program to determine the ranges of char, short,
 * int, and long variables, both signed and Unsigned, by printing
 * appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various
 * floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/* determine ranges of types                                         */
int main()
{
    system("clear");
   
/* by printing appropriate values from standard headers */
    printf("\n\nRanges of char, short, int and long varibles, both signed\nand Unsigned, by printing appropriate values from standard\nheaders\n\n");

    /* signed types                                                  */
    printf("Bits in a char      = %d\n", CHAR_BIT);
    printf("Signed char  min    = %d\n", SCHAR_MIN);
    printf("Signed char  max    = %d\n", SCHAR_MAX);
    printf("Signed short min    = %d\n", SHRT_MIN);
    printf("Signed short max    = %d\n", SHRT_MAX);
    printf("Signed int   min    = %d\n", INT_MIN);
    printf("Signed int   max    = %d\n", INT_MAX);
    printf("Signed long  min    = %ld\n", LONG_MIN);
    printf("Signed long  max    = %ld\n\n", LONG_MAX);

    /* Unsigned types                                                */
    printf("Unsigned char  max    = %u\n",  UCHAR_MAX);
    printf("Unsigned short max    = %u\n",  USHRT_MAX);
    printf("Unsigned int   max    = %u\n",  UINT_MAX);
    printf("Unsigned long  max    = %lu\n", ULONG_MAX);
 
/* by direct computation */
    printf("\n\nRanges of char, short, int and long varibles, both signed\nand Unsigned, by direct computation.\n\n\n");
    
    printf("Signed char min = %d\n", -(char)((unsigned char) ~0 >> 1));
    printf("Signed char max = %d\n", (char)((unsigned char) ~0 >> 1));

    printf("Signed short min = %d\n", -(short)((unsigned short) ~0 >> 1));
    printf("Signed short max = %d\n", (short)((unsigned short) ~0 >> 1));

    printf("Signed int min = %d\n", -(int)((unsigned int) ~0 >> 1));
    printf("Signed int max = %d\n", (int)((unsigned int) ~0 >> 1));

    printf("Signed long min = %ld\n", -(long)((unsigned long) ~0 >> 1));
    printf("Signed long max = %ld\n\n\n", (long)((unsigned long) ~0 >> 1));

    /* Unsigned types */
    printf("Unsigned char max = %u\n", (unsigned char) ~0);
    printf("Unsigned short max = %u\n", (unsigned short) ~0);
    printf("Unsigned int max = %u\n", (unsigned int) ~0);
    printf("Unsigned long max = %lu\n\n\n", (unsigned long) ~0);
}
