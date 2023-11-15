#include "unish.h"
/**
 * execute - helper function
 *@args: the array
 *@argv: the file name
 *@line: line
 *@l_cp: line copy
 *Return: void
 */
void execute(char **argv, char **args, char *line, char *l_cp)
{
	char *ac_com = NULL;
	pid_t id;

	if (args)
	{
		id = fork();
		if (id < 0)
		{
			perror(argv[0]);
			_free(line, l_cp, args, 1);
			exit(0);
		}
		else if (id == 0)
		{
			ac_com = _location(line, l_cp, args, argv);
			if (ac_com == NULL) /* handle error */
			{
				perror(argv[0]);
				_free(line, l_cp, args, 1);
				exit(126);
			}
			if (execve(ac_com, args, NULL) == -1)
			{
				perror(argv[0]);
				_free(line, l_cp, args, 1);
				exit(127);
			}
			_free(line, l_cp, args, 1);
			exit(0);
		}
		else
			wait(NULL);
	}
}
