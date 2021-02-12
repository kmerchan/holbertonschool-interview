#include "palindrome.h"

/**
 * is_palindrome - checks if given unsigned int is a palindrome
 * @n: unsigned long int to check if palindrome
 *
 * Return: returns 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long original = n, reverse = 0;
	int last = 0;

	while (n != 0)
	{
		last = n % 10;
		reverse *= 10;
		reverse += last;
		n /= 10;
	}
	if (original == reverse)
		return (1);
	return (0);
}
