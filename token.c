#include "shell.h"


char **split_input_line(char *lineptr, const char *delim)
{
	int i, num_token = 0;
	char *token;
	char **tokens;
	char *lineptr_cp = strdup(lineptr);

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
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	free(lineptr_cp);
	return (tokens);
}
