#include "shell.h"


/**
 * find_path -function finds path and checks if it exists
 *
 * @cmd: the commamd of thr path to find
 *
 * Return: file_path or NULL if path does not exist
 */

char *find_path(char *cmd)
{
	char *path, *path_cp, *file_path;
	int cmd_length;
	char *path_token;
	int token_length;
	struct stat buffer;

	/* access and store the var 'PATH' and its value */
	path = getenv("PATH");
	if (path)
	{
		path_cp = strdup(path);
		cmd_length = strlen(cmd);
		path_token = strtok(path_cp, ":");
		while (path_token != NULL)
		{
			token_length = strlen(path_token);
			file_path = malloc(cmd_length + token_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			/* check if path exists */
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cp);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cp);
		/* check if the cmd itself is a file_path that exists */
		if (stat(cmd, &buffer) == 0)
			return (cmd);

		return (NULL);
	}
	return (NULL);
}


