#include "shell.h"

/**
 * wait_for_child - waits for child process to
 * finish executing
 * @pid: process id for child
 * @shell: shell name
 * Return: void
*/
void wait_for_child(pid_t pid, char *shell)
{
	pid_t w;
	int status;

	do {
/*Check whether WCONTINUED is defined in the system or not*/
#ifdef WCONTINUED
		w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
#else
		w = waitpid(pid, &status, WUNTRACED);
#endif
		if (w == -1)
		{
			perror(shell);
			exit(EXIT_FAILURE);
		}
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

/**
 * execute_command - executes a command
 * @cmd: command to be executed
 * @shell: name of the shell program
 * Return: void
*/
void execute_command(char *cmd, char *shell)
{
	pid_t pid;
	char *arguments[100], *token, cmd_arr[MAX_CMD_LEN];
	int i;

	_strcpy(cmd_arr, cmd);
	token = strtok(cmd_arr, " ");
	for (i = 0; token; i++)
	{
		arguments[i] = malloc(_strlen(token) * sizeof(char) + 1);
		if (!arguments[i])
		{
			free_args(arguments, i);
			exit(EXIT_FAILURE);
		}
		_strcpy(arguments[i], token);
		token = strtok(NULL, " ");
	}
	arguments[i] = NULL;
	path_handler(&arguments[0]);
	pid = fork();

	if (pid == -1)
	{
		free_args(arguments, i);
		perror(shell);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(arguments[0], arguments, NULL) == -1)
			perror(shell);
		free_args(arguments, i);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait_for_child(pid, shell);
		free_args(arguments, i);
	}
}
/**
 * path_handler - handles given paths to commands
 * @command: command given
 *
 * Return: void
 */
void path_handler(char **command)
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
		free(*command);
		*command = path_command;
	}
}
