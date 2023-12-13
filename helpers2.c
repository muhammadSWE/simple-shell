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

/**
 * free_everything - frees all malloc'ed memory
 * @args: arguments list
 * @cmd: command buffer
 * @trmd_cmd: trimmed command
 * @n: number of arguments
 * Return: void
*/
void free_everything(char *args[], char *cmd, char *trmd_cmd, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(args[i]);
	if (cmd)
		free(cmd);
	free(trmd_cmd);
}

/**
 * print_env - prints environment variables
 * Return: void
*/
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}

}
