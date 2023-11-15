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
	int i, j;
	int dest_len = _strlen(dest);
	int src_len = _strlen(src);

	for (i = dest_len, j = 0; j < src_len; i++, j++)
	{
		dest[i] = src[j];
	}
	if ((unsigned long)dest_len + src_len >= sizeof(dest))
	{
		return (NULL);
	}

	dest[i] = '\0';
	return (dest);
}
