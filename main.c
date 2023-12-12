#include "main.h"

/**
* main - main entry point
* @argc: argument count
* @argv: command line arguments
* Return: 0
*/

int main(int argc, char *argv[])
{
char *pointer_to_line = NULL, **command_tokens = NULL;
size_t line_size = 0, counter = 0;
ssize_t char_read;

while (true)
{
if (isatty(STDIN_FILENO))
{
show_prompt();
}
fflush(stdout);
char_read = read_input(&pointer_to_line, &line_size);
++counter;
getline_errors(char_read, pointer_to_line);
remove_newline(pointer_to_line, char_read);
if (*pointer_to_line == '\0')
continue;
if (strcmp(pointer_to_line, "exit") == 0)
{
free(pointer_to_line);
exit(EXIT_SUCCESS);
}
if (argc > 1 && strcmp(argv[1], "env") == 0)
{
_printenv();
}
command_tokens = tokenize_command(pointer_to_line, " ");
if (command_tokens == NULL)
continue;
if (access(command_tokens[0], X_OK) == -1)
{
find_path(&command_tokens[0]);
if (command_tokens != NULL && access(command_tokens[0], X_OK) == -1)
{
fprintf(stderr, "%s: %lu: %s: not found\n", argv[0],
counter, command_tokens[0]);
deallocate_tokens(command_tokens);
continue;
}
}
execute_command(command_tokens);
free(pointer_to_line);
deallocate_tokens(command_tokens);
pointer_to_line = NULL;
command_tokens = NULL;
}
return (0);
}

