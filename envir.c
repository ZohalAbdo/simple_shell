#include "unish.h"
/**
  * envir - print enviroment.
  * @ar: command.
  */
void envir(char **ar)
{
	int i;

	if (strcmp(ar[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
