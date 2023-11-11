#include "unish.h"
/**
 *main - PID
 *@argc: numbers of argument
 *@argv: array
 *Return:Always 0
 */
int main(__attribute__((unused))int argc, char **argv, char **env)
{
	char *delim = " \n\t", *line = NULL, *l_cp = NULL;
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
		l_cp = cp_dup(line, args);
		args = malloc(sizeof(char *) * i);
		if (args == NULL)
		{
			_free(line, l_cp, NULL, 0);
			exit(EXIT_FAILURE);
		}
		strtoken(line, args, delim, l_cp);
		bye(args);
		envir(args, env);
		execute(argv, args);
		_free(NULL, l_cp, args, 1);
	}
	free(line);
	return (0);
}
