#include "shell.h"

/**
 * print_env - function prints current environment
 *
 * @env: ptr to array of environments
 * return: nothing
 */
void print_env(char **env)
{
	while (*env)
	{
		_puts(*env);
		env++;
	}
}


/**
 * dup_env - function makes copy of env
 *
 * Return: a copy of the environment variable
 */

char **dup_env()
{
	char **env_ptr = environ;
	char **env_cp =	NULL; /* Rename the variable to env_cp */
	int count = 0, i = 0;

	/* count the number of env variables */
	while (*env_ptr)
	{
		count++;
		env_ptr++;
	}
	/* allocate memory for env_copy */
	env_cp = malloc(sizeof(char *) * (count + 1));

	/* copy each env variable */
	env_ptr = environ; /* Reset env_ptr to the beginning of the environment */
	for (i = 0; i < count; i++)
	{
		env_cp[i] = _strdup(*env_ptr);
		env_ptr++;
	}
	/* null-terminate the array */
	env_cp[i] = '\0';

	return (env_cp);
}


/**
 * free_env - function frees allocated mem of env
 *
 * @env_cp: ptr to array of environs
 * return: nothing
 */

void free_env(char **env_cp)
{
	char **env_ptr = env_cp;

	while (*env_ptr != NULL)
	{
		free(*env_ptr);
		env_ptr++;
	}
	free(env_cp);
}
