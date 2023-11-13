#include "unish.h"
/**
  * cp_dup - reallocate and duplicate string.
  * @line: string.
  * @args: NULL string
  * Return: pointer.
  */
char *cp_dup(char *line, char **args)
{
	char *cp;

	cp = strdup(line);
	if (cp == NULL)
	{
		perror("tsh: memory allocation error");
		_free(line, cp, args, 0);
		exit(0);
	}
	return (cp);
}
