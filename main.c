#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments list
 * Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t len = 0;

	while (1 == 1)
	{
		print(SHELL_PROMPT);

		/*Check if reading the command gave an error*/
		if (getline(&command, &len, stdin) == -1)
		{
			/*Check if user pressed ctrl + D*/
			if (feof(stdin))
			{
				print("\n");
				exit(EXIT_SUCCESS);
			}
			/*Display error and exit due to error in reading command*/
			else
			{
				perror("Error reading the command");
				exit(EXIT_FAILURE);
			}
		}

		/*Strip the command off of new line character*/
		if (command[_strlen(command) - 1] == '\n')
			command[_strlen(command) - 1] = '\0';

		/*Execute the command*/
		execute_command(command, argv[0]);
	}

	free(command);
	return (0);
}
