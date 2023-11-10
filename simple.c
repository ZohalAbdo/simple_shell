#include "unish.h"
/**
 *main - PID
 *@argc: numbers of argument
 *@argv: array
 *Return:Always 0
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *token;
	char *delim = " \n\t";
	char *line = NULL;
	char *l_cp = NULL;
	size_t len = 0;
	char **args = NULL;
	ssize_t charno = 0;
	int i;

	errno = ENOENT;
	while (1)
	{
		i = 0;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		charno  = getline(&line, &len, stdin);
		if (charno == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_FAILURE);
		}
		l_cp = strdup(line);
		if (l_cp == NULL)
		{
			perror("tsh: memory allocation error");
			_free(line, l_cp, args, 0);
			exit(EXIT_FAILURE);
		}
		token = strtok(line, delim);
		while (token != NULL)
		{
			i++;
			token = strtok(NULL, delim);
		}
		i++;
		args = malloc(sizeof(char *) * i);
		if (args == NULL)
		{
			_free(line, l_cp, NULL, 0);
			exit(EXIT_FAILURE);
		}
		token = strtok(l_cp, delim);
		for (i = 0; token != NULL; i++)
		{
			args[i] = strdup(token);
			if (args[i] == NULL)
			{
				free(args[i]);
				_free(line, l_cp, args, 0);
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, delim);
		}
		args[i] = NULL;
		execute(argv, args);
		_free(NULL, l_cp, args, 1);
	}
	free(line);
	return (0);
}
