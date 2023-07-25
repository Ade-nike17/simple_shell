#include "shell.h"

/**
 * print_str_list - prints the string in a list/cmd
 *
 * @str: ptr to array of string
 * return: nothing
 */

void print_str_list(char **str)
{
	while (*str)
	{
		_puts(*str);
		_puts("\n");

		str++;
	}
}

/**
 * _puts - outputs a null terminated string to the standard output
 *
 * @str: pointer the the null terminated string to be printed
 * Return: the number of characters written
 */

int _puts(const char *str)
{
	int num_chars_written;

	if (str == NULL)
		return (EOF);

	num_chars_written = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		num_chars_written++;
	}

	_putchar('\n');

	num_chars_written++;


	return (num_chars_written);
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: On success 1
 *
 * on error, -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
