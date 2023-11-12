#include "unish.h"
/**
  * envir - print enviroment.
  * @ar: command.
  * @env: enviroment.
  */
void envir(char **ar, char **env)
{
	int i;

	if (strcmp(ar[0], "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
	{
		/**free(line);
		free(l_cp);
		for (i = 0; ar[i] != NULL; i++)
			free(ar[i]);
		free(ar);
		exit(EXIT_FAILURE);*/
	}
}
