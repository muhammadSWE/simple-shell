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
	char *arguments[100];
	int i = 0;

	if (!cmd)
	{
		perror(shell);
		exit(EXIT_FAILURE);
	}
	
	/*the argument parsing loop*/
	while (*cmd != '\0')
	{
		/*skip spaces at beginning*/
		while (*cmd == ' ' || *cmd == '\t' || *cmd == '\n')
			cmd++;

		if (*cmd == '\0')
			break;
		/*store the argument*/
		arguments[i++] = cmd;
		/*navigate to end of argument*/
		while (*cmd != '\0' && *cmd != ' ' && *cmd != '\t' && *cmd != '\n')
			cmd++;

		if (*cmd != '\0')
			*cmd++ = '\0';
	}
	arguments[i] = NULL;

	/*Create a child process*/
	pid = fork();

	if (pid == -1)
	{
		perror(shell);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(arguments[0], arguments, NULL))
			perror(shell);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait_for_child(pid, shell);
	}
}
