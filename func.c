#include "unish.h"
/**
 * execute - helper function
 *@args: the array
 *@argv: the file name
 *Return: void
 */
void execute(char **argv, char **args)
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
			execve(ac_com, args, NULL);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
}

