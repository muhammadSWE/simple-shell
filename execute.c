#include "shell.h"

/**
 * wait_for_child - waits for child process to
 * finish executing
 * @pid: process id for child
 * @shell: shell name
 * Return: exit status of child process
*/
int wait_for_child(pid_t pid, char *shell)
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

	return (WEXITSTATUS(status));
}

/**
 * execute_command - executes a command
 * @arguments: arguments list
 * @shell: name of the shell program
 * Return: 0 om success or 1 on failiure
*/
int execute_command(char *arguments[], char *shell)
{
	int status;
	pid_t pid;

	path_handler(&arguments[0]);
	pid = fork();

	if (pid == -1)
	{
		perror(shell);
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(arguments[0], arguments, NULL) == -1)
			perror(shell);
		return (1);
	}
	else
	{
		status = wait_for_child(pid, shell);
		return (status);
	}
}
