#include "unish.h"
/**
 * strtoken - breaks string into a series of tokens.
 * @line: the string.
 * @args: the small string.
 * @delim: the delimiter.
 * @l_cp: copy of string;
 * Return: pointer to string.
 */
char *strtoken(char *line, char **args, char *delim, char *l_cp, int *count)
{
	int i = 0;
	char *token;

	token = strtok(line, delim);
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
	}
	i++;
	token = strtok(l_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			free(args[i]);
			_free(line, l_cp, args, 0);
			exit(0);
		}
		token = strtok(NULL, delim);
	}
	*count = i;
	args[i] = NULL;
	return (*args);
}
