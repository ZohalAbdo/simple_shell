#include "unish.h"
/**
 * strtoken - breaks string into a series of tokens.
 * @line: the string.
 * @args: the small string.
 * @delim: the delimiter.
 * @l_cp: copy of string;
 * Return: pointer to string.
 */
char **strtoken(char *line, char **args, char *delim, char *l_cp)
{
	int i = 0;
	char *token;

	token = strtok(line, delim);
	if (token)
	{
		while (token != NULL)
		{
			i++;
			token = strtok(NULL, delim);
		}
		i++;
		args = malloc(sizeof(char *) * i);
		if (args == NULL)
		{
			if (line != NULL || l_cp != NULL)
				_free(line, l_cp, NULL, 0);
			exit(0);
		}
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
		args[i] = NULL;
		return (args);
	}
	free(line);
	free(l_cp);
	exit(0);
}
