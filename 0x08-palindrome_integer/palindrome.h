#ifndef PALINDROME_H
#define PALINDROME_H

/* INCLUDED LIBRARIES */
#include <stdlib.h>
#include <stdio.h>

/* FUNCTION PROTOTYPES */
/* function to check if unsigned long int is a palindrome */
int is_palindrome(unsigned long n);
/* helper function to calculate place as power of 10 based on digit count */
unsigned long power_of_ten(int digit);

#endif
