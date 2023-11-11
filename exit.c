#include "unish.h"
/**
  * bye - exit from shell
  * @ar: command line
  */
void bye(char **ar)
{
	char *first_index;

	first_index = ar[0];
	if (strcmp(first_index, "exit") == 0)
		exit(0);
}
