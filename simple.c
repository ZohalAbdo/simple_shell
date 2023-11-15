#include "unish.h"
/**
 *main - PID
 *@argc: numbers of argument
 *@argv: array
 *Return:Always 0
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *delim = " \n\t", *line = NULL, *l_cp = NULL;
	size_t len = 0;
	char **args = NULL;
	ssize_t charno = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		charno  = getline(&line, &len, stdin);
		if (charno == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(0);
		}
		if (charno <= 1)
		{
			continue; /*keep prompt display when press enter*/
		}
		l_cp = cp_dup(line);
		args = strtoken(line, args, delim, l_cp);
		bye(args, line, l_cp);
		envir(args);
		execute(argv, args, line, l_cp);
		_free(NULL, l_cp, args, 1);
	}
	free(line);
	return (0);
}
