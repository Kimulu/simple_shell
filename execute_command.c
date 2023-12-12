#include "main.h"

/**
* execute_command - executes the command
* @tokens: pointer to the tokenized input
*/

void execute_command(char **tokens)
{
pid_t command_pid;
int child_process, status;

command_pid = fork();

if (command_pid == 0)
{
child_process = execve(tokens[0], tokens, environ);

if (child_process == -1)
{
perror("execve");
}
}
else
{
wait(&status);
}
}
