#include "shell.h"

/**
 * *_strchr - locates a character in a string
 * @s: string
 * @c: character
 *
 * Return: pointer to the first occurrence of c
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	return (0);
}

/**
 * *_strcat - concatenates two strings
 * @dest: destination string parameter
 * @src: source string parameter
 *
 * Return: concatenated string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
