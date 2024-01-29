#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings), or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
	{
		format++;
	if (*format == 'c')
	{
		count += write(1, &va_arg(args, int), 1);
	}
	else if (*format == 's')
	{
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
		while (*str)
		{
			count += write(1, str, 1);
			str++;
		}
	}
	else if (*format == '%')
	{
		count += write(1, "%", 1);
	}
	else
	{
		return (-1);
	}
	}
	else
	{
		count += write(1, format, 1);
	}
		format++;
	}

	va_end(args);

	return (count);
}
