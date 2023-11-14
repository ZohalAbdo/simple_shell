#include "unish.h"
/**
  * cp_dup - reallocate and duplicate string.
  * @line: string.
  * @args: NULL string
  * Return: pointer.
  */
char *cp_dup(char *line)
{
	char *cp;

	cp = strdup(line);
	if (cp == NULL)
	{
		free(line);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (cp);
}
