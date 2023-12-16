#include "main.h"

/**
* _strtok - custom strtok function
* @string: string to be tokenized
* @dm: delimiters
* Return: pointer to the tokenized string
*/

char *_strtok(char *string, const char *dm)
{
static char *token_n;
char *token;


if (string == NULL)
{
string = token_n;
}

string = string + strspn(string, dm);
if (*string == '\0')
{
token_n = string;
return (0);
}
token = string;
string = strpbrk(token, dm);
if (string == NULL)
{
token_n = strchr(token, '\0');
}
else
{

*string = '\0';
token_n = string + 1;
}

return (token);
}
