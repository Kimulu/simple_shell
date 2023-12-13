#include "main.h"

/**
* show_prompt - prints the prompt to the screen.
* Returns nothing and takes no arguments
*/
void show_prompt(void)
{
char buf[] = "$ ";
ssize_t bytes_written;

bytes_written = write(STDOUT_FILENO, buf, strlen(buf));
if (bytes_written == -1)
{
perror("write");
exit(EXIT_FAILURE);
}
}

/**
* read_input - reads the input from the user
* @line_command: pointer to the command line input
* @length: pointer to the length of the input line
* Return: the number of bytes read
*/

ssize_t read_input(char **line_command, size_t *length)
{
ssize_t input;

input = getline(line_command, length, stdin);
return (input);
}

/**
* getline_errors - handles getline errors
* @read_characters: number of bytes read
* @line_pointer: pointer to the command line input
*/

void getline_errors(ssize_t read_characters, char *line_pointer)
{
if (read_characters == -1)
{
free(line_pointer);
line_pointer = NULL;
if (isatty(STDIN_FILENO))
printf("\n");
exit(126);
}
}

/**
* remove_newline - removes the newline character from the command line
* @command_line: pointer to the command line input
* @read_characters: number of bytes read
*/

void remove_newline(char *command_line, ssize_t read_characters)
{
int i;

for (i = 0; i < read_characters; i++)
{
if (command_line[i] == '\n')
{
command_line[i] = '\0';
break;
}
}
}

/**
* _printenv - prints current environment
* Returns nothings and takes no arguments
*/

void _printenv(void)
{
unsigned int i = 0;

while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
}
}
