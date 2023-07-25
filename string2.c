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
		puts(*str);
		puts("\n");

		str++;
	}
}
