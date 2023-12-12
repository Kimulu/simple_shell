#include "main.h"

/**
* deallocate_tokens - frees memory allocated for tokens
* @tokens: pointer to the tokenized input
*/

void deallocate_tokens(char **tokens)
{
int i;

for (i = 0; tokens[i] != NULL; i++)
{
/*free each token*/
free(tokens[i]);
tokens[i] = NULL;
}
/*free the array of tokens*/
free(tokens);
}
