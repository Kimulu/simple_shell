#include "main.h"

/**
* tokenize_command - tokenizes the command line input
* @command: pointer to the command
* @d: delimiter to split the input
* Return: pointer to the tokenized string array
*/

char **tokenize_command(char *command, const char *d)
{
char **tokens;
char *token;
int token_count = 0;

if (command == NULL || *command == '\0')
return (NULL);

tokens = malloc(1024 * sizeof(char *));
if (tokens == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = _strtok(command, d);
while (token != NULL)
{
/*save a copy of the token*/
tokens[token_count] = strdup(token);

if (tokens[token_count] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}

token_count++;
token = _strtok(NULL, d);
}
tokens[token_count] = NULL;

return (tokens);
}
