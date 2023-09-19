#include "main.h"
#include <limits.h>

/**
 * print_int - Handles Integer printing
 *@list_num: Number to be converted
 *@n: Pointer to number of characters
 *
 *Return: Void
 */
void print_int(int list_num, int *n)
{
	if (list_num == 0)
		return;
	if (list_num < 0)
	{
		_putchar('-');
		(*n)++;
		list_num = -list_num;
	}
	if (list_num == INT_MIN)
	{
		print_int((INT_MAX / 10), n);
		_putchar('0' + (-(INT_MIN % 10)));
		(*n)++;
		return;
	}
	print_int((list_num / 10), n);
	_putchar('0' + (list_num % 10));
	(*n)++;
}

/**
 * print_str - Handles string printing
 *@s: String to be printed
 *@n: Pointer to number of characters
 *
 *Return: Void
 */
void print_str(char *s, int *n)
{
	int i = 0;

	if (s == NULL)
	{
		write(2, "Error\n", 6);
		return;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		(*n)++;
	}
}

/**
 * print_bin - Handles Binary printing
 *@list_num: Number to be converted
 *@n: Number of characters
 *
 *Return: Void
 */

void print_bin(unsigned int list_num, int *n)
{
	if (list_num == 0)
		return;
	print_bin((list_num / 2), n);
	_putchar('0' + (list_num % 2));
	(*n)++;
}

/**
 * formatted - Handles formatted strings
 *@s: String character to be handled
 *@n: Pointer to number of printed characters
 *@list: Passed argument
 *Return: Number of characters printed
 */

void formatted(char s, va_list list, int *n)
{
	if (s == 'c')
		*n += _putchar(va_arg(list, int));
	else if (s == 's')
		*n += _printf(va_arg(list, char *));
	else if (s == 'd' || s == 'i')
		print_int(va_arg(list, int), n);
	else if (s == '%')
		*n += _putchar('%');
	else if (s == 'b')
		print_bin(va_arg(list, unsigned int), n);
	else if (s == 'u')
		print_uns(va_arg(list, unsigned int), n);
	else if (s == 'o')
		print_oct(va_arg(list, unsigned int), n);
	else
	{
		_putchar('%');
		(*n)++;
		_putchar(s);
		(*n)++;
	}

}

/**
 * _printf - Custom printf implementation
 *@format: String format passed as argument
 *
 *Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int printed = 0, i;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
			printed++;
			continue;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			formatted(format[i], list, &printed);
			i++;
			continue;
		}
		i++;
		continue;
	}
	va_end(list);

	return (printed);
}
