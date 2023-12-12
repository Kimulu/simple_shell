#include "main.h"

/**
* tokenize_command - tokenizes the command line input
* @command: pointer to the command
* @d: delimiter to split the input
* Return: pointer to the tokenized string array
*/

char **tokenize_command(char *command, const char *d)
{
char **tokens = NULL;
char *tokenizer, *ptr;
size_t token_count;
int i = 0;

if (command == NULL || *command == '\0')
return (NULL);

/*count tokens*/
token_count = 0;
ptr = strdup(command);
while (ptr != NULL)
{
token_count++;
ptr = strchr(ptr, d[0]);
if (ptr != NULL)
ptr++;
}
free(ptr);
ptr = NULL;

if (token_count > 0)
{
/*allocate memory using token count*/
tokens = malloc(sizeof(char *) * (token_count + 1));
if (tokens == NULL)
exit(EXIT_FAILURE);

tokenizer = strtok(command, d);

while (tokenizer != NULL)
{
tokens[i] = strdup(tokenizer);
tokenizer = strtok(NULL, d);
i++;
}
tokens[i] = NULL;
}
return (tokens);
}

