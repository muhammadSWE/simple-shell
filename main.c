#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments list
 * Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *command = NULL, *trimmed_command, *arguments[100];
	int args_num, status = 0;
	size_t len = 0;
	ssize_t read;
	(void)argc;

	while (1 == 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			print(SHELL_PROMPT);

		read = getline(&command, &len, stdin);
		if (read == -1 || len > MAX_CMD_LEN)
		{
			if (command)
				free(command);
			exit(EXIT_SUCCESS);
		}
		trimmed_command = trim_whitespace(command);
		if (!trimmed_command)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		args_num = tokenize(&*arguments, trimmed_command);
		if (strcmp(arguments[0], "exit") == 0)
		{
			free_everything(arguments, command, trimmed_command, args_num);
			break;
		}
		else if (strcmp(arguments[0], "env") == 0)
			print_env();
		else
			status = execute_command(&*arguments, argv[0]);
		free_everything(arguments, command, trimmed_command, args_num);
		command = NULL;
		if (status == 127)
			return (status);
	}

	return (status);
}
