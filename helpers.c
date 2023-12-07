#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
*/
int _strlen(const char *s)
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

/**
 * _isspace - check if a character is whitespace or not
 * @c: character to be checked
 * Return: 1 if c is whitespace or 0 if not
*/
int _isspace(int c)
{
	return
	(c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

/**
 * trim_whitespace - removes whitespace from a string
 * @str: string to trim
 * Return: trimmed string
*/
char *trim_whitespace(const char *str)
{
	char *result;
	int i, j, c;

	if (!str)
		return (NULL);

	i = 0;
	while (_isspace(str[i]))
		i++;

	if (i >= _strlen(str))
		return (NULL);

	j = _strlen(str) - 1;
	while (j > i && _isspace(str[j]))
		j--;

	result = malloc((j - i + 2) * sizeof(char));

	for (c = 0; i <= j; c++)
	{
		result[c] = str[i];
		i++;
	}

	return (result);
}
