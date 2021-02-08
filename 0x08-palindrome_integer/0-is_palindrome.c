#include "palindrome.h"

/**
 * is_palindrome - checks if given unsigned int is a palindrome
 * @n: unsigned long int to check if palindrome
 *
 * Return: returns 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	/* ULONG_MAX = 18446744073709551615, with max digits = 20 */
	int digit = 19, first = 0, last = 0;

	while (n / (power_of_ten(digit)) == 0)
		digit--;
	while (n)
	{
		first = n / (power_of_ten(digit));
		last = n % 10;
		if (first != last)
			return (0);
		n %= (power_of_ten(digit));
		n /= 10;
		digit -= 2;
	}
	return (1);
}

/**
 * power_of_ten - finds 10 raised to the power of digit
 * used to determine the place value of the digit
 *
 * @digit: number to raise 10 to the power of; count of digit
 *
 * Return: unsigned int representing the digit place value
 */

unsigned long power_of_ten(int digit)
{
	unsigned long value = 1;

	while (digit)
	{
		value *= 10;
		digit--;
	}
	return (value);
}
