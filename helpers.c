#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;

	return (i);
}

/**
 * print - prints a message to stdout
 * @string: message to be printed
 * Return: void
*/
void print(char *string)
{
	write(STDOUT_FILENO, string, _strlen(string));
}
