#include "main.h"
#include <stdio.h>

/**
 * main - function to control program execution
 * Return: (0) on successful execution.
 */
int main(void)
{
	if (isInteractiveMode())
	{
		char *userInput = NULL;
		size_t bufferSize = 0;

		do {
			displayPrompt();
			if (getline(&userInput, &bufferSize, stdin) == -1)
			{
				printf("\nProgram terminated.\n");
				free(userInput);
				break;
			}
			userInput[strcspn(userInput, "\n")] = '\0';
			if (strlen(userInput) > 0)
			{
				executeCommand(userInput);
			}
			else
			{
				handleInputError();
			}

		} while (1); /* Infinite loop until Ctrl+D is pressed */

		free(userInput);
	}
	else
	{
		/* Run shell scripts for non-interactive mode */
		runShellScripts();
	}

	return (0);
}

