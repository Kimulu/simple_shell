#include "main.h"

/**
* execute_command - executes the command
* @tokens: pointer to the tokenized input
*/

void execute_command(char **tokens)
{
pid_t command_pid;
int status;

command_pid = fork();

if (command_pid == 0)
{
if (access(tokens[0], X_OK) == 0)
{
if (execve(tokens[0], tokens, environ) == -1)
{
perror("1");
exit(1);
}
}
}

else if (command_pid == -1)
{
perror("2");
free(tokens);
tokens = NULL;
exit(1);
}
else
{
waitpid(command_pid, &status, 0);
}
}
