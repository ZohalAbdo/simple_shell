#include "unish.h"
/**
 * execute - helper function
 *@args: the array
 *@argv: the file name
 *Return: void
 */
void execute(char **argv, char **args, char *line, char *l_cp)
{
	char *ac_com = NULL;
	pid_t id;
/*	pid_t child_id;*/
	int i;

	if (args)
	{
		id = fork();
		if (id < 0)
		{
			perror(argv[0]);
			free(line);
			free(l_cp);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(0);
		}
		else if (id == 0)
		{
			ac_com = _location(line, l_cp, args, argv);
			if (ac_com == NULL) /* handle error */
			{
				perror(argv[0]);
				free(line);
				free(l_cp);
				for (i = 0; args[i] != NULL; i++)
					free(args[i]);
				free(args);
				exit(126);
			}
			/*  */
			if (execve(ac_com, args, NULL) == -1)
			{
				perror(argv[0]);
				free(line);
				free(l_cp);
				for (i = 0; args[i] != NULL; i++)
					free(args[i]);
				free(args);
				exit(127);
			}
			free(line);
			free(l_cp);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	
}
