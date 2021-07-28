#include "holberton.h"

/**
 * wildcmp - compares two strings recursively
 * one string can contain wildcard chracters that represent any string
 *
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Return: 1 if the strings are considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	int wildcard = 0;

	if (s1 && s2 == NULL)
		return (1);
	if (s1 == NULL)
		return (0);
	if (s2 == NULL)
		return (0);
	if (s2[0] == '*')
	{
		wildcard++;
		s2 = forward_wildcard(s2);
		s1 = forward_to_char(s1, s2[0]);
	}
	if (s1[0] != s2[0])
		return (0);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	s1++;
	s2++;
	return (wildcmp(s1, s2));
}

/**
 * forward_wildcard - moves the second string past wildcard characters
 *
 * @s2: the second string to move
 *
 * Return: new pointer to the second string at next character after wildcards
 */
char *forward_wildcard(char *s2)
{
	if (s2[0] == '*')
	{
		s2++;
		return (forward_wildcard(s2));
	}
	return (s2);
}

/**
 * forward_to_char - moves the first string to the next matching character
 * or null byte, if there is no possible match
 *
 * @s1: the first string to move
 * @c: the character to match
 *
 * Return: new pointer to the first string at matching character or null byte
 */
char *forward_to_char(char *s1, char c)
{
	if (s1[0] != c && s1[0] != '\0')
	{
		s1++;
		return (forward_to_char(s1, c));
	}
	return (s1);
}
