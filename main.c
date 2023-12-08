#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 100

void processInteractiveMode() {
    char *userInput = NULL;
    size_t bufferSize = 0;

    while (1) {
        displayPrompt();
        if (getline(&userInput, &bufferSize, stdin) == -1) {
            printf("\nProgram terminated.\n");
            free(userInput);
            break;
        }

        userInput[strcspn(userInput, "\n")] = '\0';
        if (strlen(userInput) > 0) {
            char *command = strtok(userInput, " ");
            char *args[MAX_ARGS] = {NULL};
            for (int j = 0; (args[j] = strtok(NULL, " ")) != NULL; j++);

            executeCommand(command, args);
        } else {
            handleInputError();
        }
    }
}

void processNonInteractiveMode(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        char *command = strtok(argv[i], " ");
        char *args[MAX_ARGS] = {NULL};
        for (int j = 0; (args[j] = strtok(NULL, " ")) != NULL; j++);

        executeCommand(command, args);
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        processNonInteractiveMode(argc, argv);
    } else {
        processInteractiveMode();
    }

    return 0;
}

