#include "main.h"

/**
* _getenv - retrieves the environment variable
* @name: name of the environment variable to search for
* Return: pointer to the value of the environment variable
*/

char *_getenv(const char *name)
{
char *value, *path;
char *path_copy = NULL;
const char *env_var;
size_t name_len = strlen(name);
size_t i;

for (i = 0; environ[i] != NULL; i++)
{
env_var = environ[i];
if (strncmp(env_var, name, name_len) == 0)
{
value = strchr(env_var, '=');
if (value == NULL)
{
return (NULL);
}
path = (value + 1);
path_copy = strdup(path);
return (path_copy);
}
}
return (path_copy);
}
