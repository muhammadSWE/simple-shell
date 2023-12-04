#ifndef SHELL_H

#define SHELL_H

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*Constants definitions*/
#define MAX_CMD_LEN 1024
#define SHELL_PROMPT "simple_shell$ "

/*Function prototypes*/

/*Helper functions*/
int _strlen(char *s);
void print(char *string);

/*Main functions*/
void execute_command(char *cmd, char *shell);
void wait_for_child(pid_t pid, char *shell);

/*End of function prototypes*/

#endif /*SHELL_H*/
