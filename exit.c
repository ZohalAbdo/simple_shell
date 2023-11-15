#include "unish.h"
/**
  * bye - exit from shell
  * @ar: command line
  * @line: input from user
  * @l_cp: strdup return
  */
void bye(char **ar, char *line, char *l_cp)
{
	char *first_index;
	int i;

	first_index = ar[0];
	if (strcmp(first_index, "exit") == 0)
	{
		for (i = 0; ar[i] != NULL; i++)
			free(ar[i]);
		free(ar);
		free(line);
		free(l_cp);
		exit(EXIT_SUCCESS);
	}
}
