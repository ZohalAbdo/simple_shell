#include "unish.h"
/**
 * _strcat -concatenates two strings
 * @dest: first string
 * @src: secound string
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	for ( ; dest[i] != '\0'; )
	{
		i++;
	}
	j = 0;
	for ( ; src[j] != '\0'; )
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if ((long unsigned int)_strlen(dest) + _strlen(src) >= sizeof(dest))
	{
		return (NULL);
	}

	dest[i] = '\0';
	return (dest);
}
