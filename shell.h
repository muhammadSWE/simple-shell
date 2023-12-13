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
#define EXIT_CMD 10

/*Environment variables*/
extern char **environ;

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
int execute_command(char *arguments[], char *shell);
int wait_for_child(pid_t pid, char *shell);
void free_everything(char *args[], char *cmd, char *trmd_cmd, int n);
void path_handler(char **command);
int tokenize(char **args_list, char *buffer);
void print_env(void);
/*End of function prototypes*/

#endif /*SHELL_H*/
