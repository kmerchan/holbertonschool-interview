#ifndef HOLBERTON_H
#define HOLBERTON_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */
/* writes single character to standard output */
int _putchar(char c);
/* prints error message and exits with error code (\*/
void error(void);
/* checks if number consists of only digits and returns digit count */
int digit_check(char *number);
/* sets the maximum and minimum number of digits and corresponding numbers */
void set_max_min(int digit_count1, int digit_count2,
		 int *max_digit, int *min_digit,
		 char **num1, char **num2, char *arg1, char *arg2);
/* mallocs and initializes a 2D array */
char **create_double(int row_size, int column_size);
/* mallocs and sets final array with sum of intermediary calculations */
char *create_final(int size, char **calculation);
/* reallocates final array to remove any leading zeros */
char *final_realloc(char *final, char **calculation);

#endif
