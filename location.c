#include "unish.h"
/**
 * tokpath - break the path.
 * @l_cp: line copy
 * @line: line
 * @args: arguments
 * @argv: values of arg
 * @cp_path: copy of path.
 * @l_c: path length.
 * Return: pointer.
 */
char *tokpath(char *cp_path, int l_c, char *line, char *l_cp,
		char **args, char **argv)
{
	char *tok_path, *file_path, *command = NULL;
	int len_dir;
	struct stat buffer;

	command = args[0];
	tok_path = strtok(cp_path, ":");
	while (tok_path != NULL)
	{
		len_dir = _strlen(tok_path);
		file_path = malloc(l_c + len_dir + 2);
		if (file_path == NULL)
		{
			perror("tsh: memory allocation error");
			free(cp_path);
			exit(EXIT_FAILURE);
		}
		_strcpy(file_path, tok_path);
		_strcat(file_path, "/");
		_strcat(file_path, command);
		_strcat(file_path, "\0");
		if (stat(file_path, &buffer) == 0)
		{
			if  (access(file_path, X_OK) == 0)
			{
				free(cp_path);
				return (file_path);
			}
		}
		else
		{
			free(file_path);
			tok_path = strtok(NULL, ":");
		}
	}
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
	free(cp_path);
	_free(line, l_cp, args, 1);
	exit(127);
}
/**
 * _location - location function
 * @line: line
 * @l_cp: line copy
 * @args: arguments
 * @argv: values of the arguments
 * Return: file path
 */
char *_location(char *line, char *l_cp, char **args, char **argv)
{
	char *path, *cp_path, *ptok, *command = NULL;
	int len_c;

	command = args[0];
	path = getenv("PATH");
	if (path)
	{
		cp_path = _strdup(path);
		if (cp_path == NULL)
		{
			perror("tsh: memory allocation error");
			exit(EXIT_FAILURE);
		}
		len_c = _strlen(command);
		ptok = tokpath(cp_path, len_c, line, l_cp, args, argv);
		if (ptok != NULL)
			return (ptok);
		exit(127);
	}
	exit(0);
}
