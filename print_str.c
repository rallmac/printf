#include "main.h"

/**
 * _strlen - finds the length of a string.
 * @s: string
 * Return: printed integer.
 */

int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}

/**
 * _strlenc - finds length of a string but for constant characters
 * @s: string
 * Return: printed integer
 */

int _strlenc(const char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}

