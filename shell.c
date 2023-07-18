#include "shell.h"

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 for success always
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	/* make void parameters in main */
	char *lineptr;
	size_t n = 0;

	printf("$ ");
	getline(&lineptr, &n, stdin);

	printf("%s", lineptr);

	free(lineptr);
	return (0);
}
