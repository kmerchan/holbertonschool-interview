#include "substring.c"

/**
 * find_substring - finds all possible substrings containing list of words
 * @s: the string to scan
 * @words: the array of words all substrings must be concatenation of
 * @nb_words: the number of elements in the array words
 * @n: pointer to which to store the number of elements in the returned array
 *
 * Return: array storing each index in s at which a substring was found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	unsigned int word = 0, i = 0, match = 0;
	int *word_used = NULL;

	*n = NULL;

	word_used = malloc(sizeof(int) * nb_words);
	if (word_used == NULL)
		return (NULL);
	for (word = 0; word < nb_words; word++)
		word_used[word] = -1;
	for (i = 0; s[i]; i++)
	{
		for (word = 0; word < nb_words; word++)
		{
			if (word_used[word] != -1)
				continue;
			match = string_compare(s, i, words[word]);
			if (match != 0)
			{
				
			}
		}
	}
}

/**
 * string_compare - compares two strings to see if one contains the other
 * @s1: the first string to compare, the longer of the strings
 * @i: the index of the first string to start from
 * @s2: the second string to compare, the shorter of the strings
 *
 * Return: length of the shorter word contained or 0 if no match
 */
int string_compare(char const *s1, unsigned int i, char const *s2)
{
	unsigned int j = 0;

	for (j = 0; s1[i] && s2[j]; i++, j++)
	{
		if (s1[i] != s2[j])
			return (0);
	}
	return (j);
}

/**
 * string_length - finds the length of a string
 * @str: the string to get length of
 *
 * Return: length of the string
 */
int string_length(char const *str)
{
	unsigned int i = 0;

	for (i = 0; str[i]; i++)
		continue;
	return (i);
}
