#include "shell.h"


/**
 * execmd - function executes inputted cmd
 *
 * @tokens: pointers to an array of string that holds cmd emtered
 *
 * @env: pointer to an array of environments
 *
 * Return: function returns nothing
 */
void execmd(char **tokens)
{
	char *xact_cmd = find_path(tokens[0]);
	pid_t pid;
	int status;

	if (tokens == NULL || tokens[0] == NULL)
		return;

	/* check if cmd exists */
	if (xact_cmd == NULL)
	{
		perror("Error");
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		/* child process exec the cmds */
		if (execve(xact_cmd, tokens, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(xact_cmd);
}

