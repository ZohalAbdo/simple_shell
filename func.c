#include "unish.h"
/**
 * execute - helper function
 *@args: the array
 *@argv: the file name
 *Return: void
 */
void execute(char **argv, char **args, char **env, char *line, char *l_cp)
{
	char *ac_com = NULL;
	pid_t id;
	int i;

	if (args)
	{
		id = fork();
		if (id == -1)
		{
			perror(argv[0]);
			free(line);
			free(l_cp);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(EXIT_FAILURE);
		}
		else if (id == 0)
		{
			ac_com = _location(line, l_cp, args);
			if (execve(ac_com, args, env) == -1)
			{
				perror(argv[0]);
				free(line);
				free(l_cp);
				for (i = 0; args[i] != NULL; i++)
					free(args[i]);
				free(args);
				exit(126);
			}
			free(line);
			free(l_cp);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
	}
	
}
