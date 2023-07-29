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
	char **env_cp = dup_env();
	int i;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 3);
		tokens = get_input_tokens();
		if (tokens == NULL)
		{
			break;
		}
		/* check if the entered command is exitor env */
		if (tokens != NULL)
		{
			if (should_exit(tokens[0]))
			{
				handle_exit(tokens, env_cp);
			}
			if (is_env_cmd(tokens[0]))
			{
				handle_env(tokens, env_cp);
				continue;
			}
			/* Remove the prompt before executing the command */
			if (fork() == 0)
			{
				execmd(tokens);
				exit(EXIT_SUCCESS);
			}
			wait(NULL);
		}
		/* Free the allocated memory for token */
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
	free_env(env_cp);
	return (0);
}
