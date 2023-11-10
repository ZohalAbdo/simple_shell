#include "unish.h"
/**
 * _location - location function
 *@command: command
 *Return: file path
 */
char *_location(char *command)
{
	char *path, *cp_path, *tok_path, *file_path;
	int len_c, len_dir;
	struct stat buffer;

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
		tok_path = strtok(cp_path, ":");
		while (tok_path != NULL)
		{
			len_dir = _strlen(tok_path);
			file_path = malloc(len_c + len_dir + 2);
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
				free(cp_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				tok_path = strtok(NULL, ":");
			}
		}
		free(cp_path);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}