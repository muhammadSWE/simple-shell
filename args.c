#include "shell.h"

/**
 * free_args - frees arguments list
 * @args: arguments list
 * @n: number of arguments
 * Return: void
*/
void free_args(char *args[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(args[i]);
}
