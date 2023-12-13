#include "shell.h"

/**
 * tokenize - split cmd string into tokens list
 * @args_list: list of cmd args
 * @buffer: command string
 * Return: number of arguments
*/
int tokenize(char **args_list, char *buffer)
{
	char *token, cmd_arr[MAX_CMD_LEN];
	int i;

	_strcpy(cmd_arr, buffer);
	token = strtok(cmd_arr, " ");
	for (i = 0; token; i++)
	{
		args_list[i] = malloc(_strlen(token) * sizeof(char) + 1);
		if (!args_list[i])
			exit(EXIT_FAILURE);
		_strcpy(args_list[i], token);
		token = strtok(NULL, " ");
	}
	args_list[i] = NULL;
	return (i);
}

/**
 * path_handler - handles given paths to commands
 * @command: command given
 * Return: 0 on success or 127 if cmd not found
 */
int path_handler(char **command, char *shell)
{
	if (strchr(*command, '/') == NULL)
	{
		int i = sizeof(char);
		char *path_command = malloc((_strlen("/bin/") + _strlen(*command) + 1) * i);

		if (!path_command)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		_strcpy(path_command, "/bin/");
		_strcat(path_command, *command);
		if (access(path_command, F_OK | X_OK) != 0)
		{
			cmd_not_found(*command, shell);
			free(path_command);
			return (127);
		}
		free(*command);
		*command = path_command;
	}
	return (0);
}
