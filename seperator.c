#include "unish.h"
/**
  * separator - separate command and executed in new line.
  * @ar: command line.
  */
void separator(char *ar)
{
	char *s, *new;
	int i = 0;

	new = strdup(ar);
	s = strtok(ar, ";");
	while (s != NULL)
	{
		i++;
		write(STDOUT_FILENO, s, _strlen(s));
		write(STDOUT_FILENO, "\n", 1);
		s = strtok(NULL, ";");
	}
	free(new);
}
