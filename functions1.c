#include "main.h"

/******************* PRINT UNSIGNED NUMBER *********************/
/**
 * print_unsigned - prints an unsigned number
 * @types: list array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: Prints the number of characters
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/******************** PRINT UNSIGNED NUMBER IN OCTAL ********************/
/**
 * print_octal - prints an unsigned number in octal notation
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***************** PRINT UNSIGNED NUMBER IN HEXADECIMAL ************/
/**
 * print_hexadecimal - this prints an unsigned number in hexadecimal notation
 * @types: List arrays of arguments
 * @buffer: Buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/*************** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL*************/
/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal notation
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets the width
 * @precision: specifies precision
 * @size: specifies the size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/****************** PRINT HEX NUMBER IN LOWER OR UPPER ***********/
/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @types: list arrays of arguments
 * @map_to: array of values to map the number to
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @flags_ch: calculates active flags
 * @width: gets the width
 * @precision: precision specification
 * @size: specifies the size
 * Return: number of characters to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flags_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flags_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

