#include "main.h"
#include <stdio.h>

int main() {
    if (isInteractiveMode()) {
        char *userInput = NULL;
        size_t bufferSize = 0;

        do {
            /*Display prompt*/
            displayPrompt();

            /*Get user input using getline*/
            if (getline(&userInput, &bufferSize, stdin) == -1) {
                /*Handle end-of-file (Ctrl+D)*/
                printf("\nProgram terminated.\n");
                free(userInput);
                break;
            }

            userInput[strcspn(userInput, "\n")] = '\0';

            /*Check if user wants to execute a command*/
            if (strlen(userInput) > 0) {
                executeCommand(userInput);
            } else {
                handleInputError();
            }

        } while (1); /*Infinite loop until Ctrl+D is pressed*/

        free(userInput);
    } else {
        /*Run shell scripts for non-interactive mode*/
        runShellScripts();
    }

    return 0;
}
