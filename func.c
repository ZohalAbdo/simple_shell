#include "unish.h"
/**
 * execute - helper function
 *@args: the array
 *@argv: the file name
 *Return: void
 */
void execute(char **argv, char **args, char **env)
{
	char *ac_com = NULL, *command = NULL;
	pid_t id;

	if (args)
	{
		command = args[0];
		id = fork();
		if (id == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else if (id == 0)
		{
			ac_com = _location(command);
			if (execve(ac_com, args, env) == -1)
			{
				perror(argv[0]);
				exit(126);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
	}
	
}
