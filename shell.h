#ifndef SHELL_H

#define SHELL_H

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/*Constants definitions*/
#define MAX_CMD_LEN 16384
#define SHELL_PROMPT "simple_shell$ "

/*Function prototypes*/

/*Helper functions*/
int _strlen(const char *s);
void print(char *string);
int _isspace(int c);
char *trim_whitespace(const char *str);
char *_strcpy(char *dest, char *src);

/*Helper 2 Functions*/
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);

/*Main functions*/
void execute_command(char *cmd, char *shell);
void wait_for_child(pid_t pid, char *shell);
void free_args(char *args[], int n);
void path_handler(char **command);
/*End of function prototypes*/

#endif /*SHELL_H*/
