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
	char *argv[2];
	pid_t pid;

	argv[0] = cmd;
	argv[1] = NULL;

	/*Create a child process*/
	pid = fork();
	if (pid < 0)
	{
		perror(shell);
		exit(1);
	}

	/*If this is the chile process, execute the command*/
	if (pid == 0)
	{
		/*Check if there was a problem in executing the command*/
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(shell);
			exit(EXIT_FAILURE);
		}
	}
	/*If this is the parent process, wait for the child process*/
	else
	{
		wait_for_child(pid, shell);
	}
}
