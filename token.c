#include "shell.h"


/**
 * split_input_line - function splits input cmd into tokens
 *
 * @lineptr: ptr holding an array of strings
 * @delim: separators for the string
 *
 * Return: tokens
 */

char **split_input_line(char *lineptr, const char *delim)
{
	int i, num_token = 0;
	char *token;
	char **tokens;
	char *lineptr_cp = _strdup(lineptr);

	/* calculate the no of token */
	token = strtok(lineptr_cp, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	/* allocate mem to to store token array */
	tokens = malloc(sizeof(char *) * (num_token + 1));
	/* store each of the tokens in the token arr */
	token = strtok(lineptr, delim);

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	free(lineptr_cp);
	return (tokens);
}



/**
 * get_input_tokens - function takes in input cmd
 *
 * Return: tokens
 */

char **get_input_tokens()
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t line_read;
	char **tokens;

	line_read = getline(&lineptr, &n, stdin);
	/*  condition for EOF or Ctrl + D */
	if (line_read == -1)
	{
		free(lineptr);
		return (NULL);
	}

	/* remove new line at the end */
	lineptr[line_read - 1] = '\0';

	/* split the input line into tokens*/
	tokens = split_input_line(lineptr, " ");
	free(lineptr);

	return (tokens);
}

