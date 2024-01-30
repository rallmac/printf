#include "main.h"

/**
 * is_printable - Evaluates if a caracter is printable
 * @c: character to be evaluated
 *
 * Return: 1 if c is printable, 0 if otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - append ascci in hexadecimal code to buffer
 * @buffer: array of characters
 * @i: index at which to start appending
 * @ascii_code: ASSCI CODE
 *
 * Return: 3 always
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* the hexa format code which is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (0);
}

/**
 * convert_size_number - casts a number to its specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - casts a number to the specified size
 * @num: number to be casted
 * @size: number inicating the type to be casted
 *
 * Return: casted value of the number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
