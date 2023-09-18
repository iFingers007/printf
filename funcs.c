#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_uns - Prints unsigned integer
 *@num: Unsigned int to be printed
 *@n: Pointer to number of characters printed
 *Return: Void
 */

void print_uns(unsigned int num, int *n)
{
	if (num == 0)
		return;
	print_uns((num / 10), n);
	_putchar('0' + (num % 10));
	(*n)++;
}

/**
 * print_oct - Handles octal printing
 *@list_num: Number to be converted
 *@n: Number of characters
 *
 *Return: Void
 */

void print_oct(unsigned int list_num, int *n)
{
	if (list_num == 0)
		return;
	print_oct((list_num / 8), n);
	_putchar('0' + (list_num % 8));
	(*n)++;
}
