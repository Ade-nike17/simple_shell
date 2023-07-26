#include "shell.h"


/**
 * should_exit - function compares ptr to cmd with exit
 *
 * @cmd: ptr to cmds
 *
 * Return: string compare of cmd and exit
 */

int should_exit(const char *cmd)
{
	return (_strcmp(cmd, "exit") == 0);
}

/**
 * is_env_cmd - function compares ptr to cmd with env
 *
 * @cmd: ptr to cmds
 *
 * Return: string compare of cmd and env
 */

int is_env_cmd(const char *cmd)
{
	return (_strcmp(cmd, "env") == 0);
}


/**
 * handle_exit - function exits shell
 *
 * @tokens: ptr to array of tokenized cmds
 * @env_cp: ptr to array of copies of env
 *
 * Return: nothing
 */

void handle_exit(char **tokens, char **env_cp)
{
	int i;

	free_env(env_cp);
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
	exit(EXIT_SUCCESS);
}


/**
 * handle_env - function prints current env
 *
 * @tokens: ptr to array of tokenized cmds
 * @env_cp: ptr to array of copies of env
 *
 * Return: nothing
 */

void handle_env(char **tokens, char **env_cp)
{
	int i;

	print_env(env_cp);
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
