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
	char prompt[] = "$ ";

	while (1)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		tokens = get_input_tokens();
		if (tokens == NULL)
		{
			/* free env before exiting shell */
			free_env(env_cp);
			return (-1);
		}
		/* check if the entered command is exit */
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free_env(env_cp);
			/* Free the allocated memory for tokens */
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			exit(EXIT_SUCCESS);
		}
		/* check if the entered command is env */
		if (_strcmp(tokens[0], "env") == 0)
		{
			print_env(env_cp);
			/* Free the allocated memory for tokens */
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			continue;
		}

		execmd(tokens);

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

