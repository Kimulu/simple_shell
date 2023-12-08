#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 100

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        // Non-interactive mode, execute command line arguments
        for (int i = 1; i < argc; i++)
        {
            // Split the command and its arguments
            char *command = strtok(argv[i], " ");
            char *args[MAX_ARGS];  // Assuming a maximum number of arguments
            int j = 0;

            // Populate the args array
            while ((args[j] = strtok(NULL, " ")) != NULL)
            {
                j++;
            }
            args[j] = NULL;  // Ensure the args array is NULL-terminated

            executeCommand(command, args);
        }
    }
    else
    {
        // Interactive mode
        char *userInput = NULL;
        size_t bufferSize = 0;

        do
        {
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
                // Split the input into command and arguments
                char *command = strtok(userInput, " ");
                char *args[MAX_ARGS];  // Assuming a maximum number of arguments
                int j = 0;

                // Populate the args array
                while ((args[j] = strtok(NULL, " ")) != NULL)
                {
                    j++;
                }
                args[j] = NULL;  // Ensure the args array is NULL-terminated

                executeCommand(command, args);
            }
            else
            {
                handleInputError();
            }

        } while (1); /* Infinite loop until Ctrl+D is pressed */

        free(userInput);
    }

    return 0;
}
