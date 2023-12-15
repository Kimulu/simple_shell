#include "main.h"

/**
* find_path - finds the path of the command
* @full_path: pointer to the command
*/

void find_path(char **full_path)
{
char *get_path_variable;
char **directory_tokens = NULL;
char *temp_path;
int i = 0;

if (*full_path == NULL || full_path == NULL)
return;

get_path_variable = getenv("PATH");
if (get_path_variable  == NULL)
return;
directory_tokens = tokenize_command(get_path_variable, ":");
if (directory_tokens == NULL)
return;

while (directory_tokens[i] != NULL)
{
temp_path = malloc(sizeof(char) * (strlen(*full_path) +
strlen(directory_tokens[i]) + 2));
if (temp_path == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
return;
}
strcpy(temp_path, directory_tokens[i]);
strcat(temp_path, "/");
strcat(temp_path, *full_path);

if (access(temp_path, X_OK) == 0)
{
free(*full_path);
*full_path = strdup(temp_path);
free(temp_path);
break;
}
free(temp_path);
i++;
}
deallocate_tokens(directory_tokens);
}
