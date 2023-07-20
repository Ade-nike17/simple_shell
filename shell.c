#include "shell.h"

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 for success always
 */

int main(__attribute__((unused))int argc, char **argv)
{
	char *lineptr = NULL;
	char **tokens;
	size_t n = 0;
	ssize_t line_read;
	pid_t pid;
	int i, status;

	/* set function in an infinite loop */
	while (1)
	{
		printf("$ ");
		line_read = getline(&lineptr, &n, stdin);
		/*  condition for EOF or Ctrl + D */
		if (line_read == -1)
			break;

		/* remove new line at the end */
		lineptr[line_read - 1] = '\0';

		/* split the input line into tokens*/
		tokens = split_input_line(lineptr, " ");
		/* fork child process */
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			/* child process exec cmd */
			if (execve(lineptr, argv, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* parent process wait for child process */
			wait(&status);
		}

	}
	/* free the allocated mem for tpkens */
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
	/* free up the allocated mem */
	free(lineptr);
	return (0);
}
