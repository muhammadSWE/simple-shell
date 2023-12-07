#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments list
 * Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *command = NULL, *trimmed_command;
	size_t len = 0;
	ssize_t read;
	(void)argc;

	while (1 == 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			print(SHELL_PROMPT);

		/*Check if reading the command gave an error*/
		read = getline(&command, &len, stdin);
		if (read == -1 || len > MAX_CMD_LEN)
		{
			if (command)
				free(command);
			exit(EXIT_SUCCESS);
		}
		/*Remove whitespace from command*/
		trimmed_command = trim_whitespace(command);
		if (!trimmed_command)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		/*Execute the command*/
		execute_command(trimmed_command, argv[0]);

		if (command)
			free(command);
		free(trimmed_command);
		command = NULL;
	}

	return (0);
}
