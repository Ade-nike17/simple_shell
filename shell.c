#include "shell.h"


int main(__attribute__((unused)) int argc, __attribute__((unused))char **argv)
{
	char **tokens;
	int i;

	while (1)
	{
		tokens = get_input_tokens();
		if (tokens == NULL)
		{
			return (-1);
		}

		execmd(tokens);

		/* Free the allocated memory for tokens */
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}

	return (0);
}

