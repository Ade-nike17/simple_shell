#include "shell.h"

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 for success
 */
int main(__attribute__((unused)) int argc, __attribute__((unused))char **argv)
{
	char **tokens;
	int i;
	char **env_cp = dup_env();

	while (1)
	{
		tokens = get_input_tokens();
		if (tokens == NULL)
		{
			/* free env before exiting shell */
			free_env(env_cp);
			return (-1);
		}

		execmd(tokens, env_cp);

		/* Free the allocated memory for tokens */
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);

	}
	free_env(env_cp);
	return (0);
}

