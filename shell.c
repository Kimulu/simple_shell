#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * displayPrompt - Displays a prompt for the user in interactive mode.
 */
void displayPrompt(void)
{
    printf("$ ");
    fflush(stdout);
}

/**
 * isInteractiveMode - Checks if the program is in interactive mode.
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int isInteractiveMode(void)
{
    return (isatty(fileno(stdin)));
}

/**
 * executeCommand - Executes the provided command.
 * @command: The command to be executed.
 */

void executeCommand(char *command, char *args[]) {
    pid_t pid = fork();

    if (pid == 0) {
        if (strchr(command, '/') == NULL) {
            // Handle PATH
            char *path = getenv("PATH");
            char *token = strtok(path, ":");

            while (token != NULL) {
                char *fullPath = malloc(strlen(token) + strlen(command) + 2);
                if (fullPath == NULL) {
                    perror("Error allocating memory");
                    _exit(EXIT_FAILURE);
                }

                strcpy(fullPath, token);
                strcat(fullPath, "/");
                strcat(fullPath, command);

                execv(fullPath, args);

                free(fullPath);
                token = strtok(NULL, ":");
            }

            perror("Command not found");
            _exit(EXIT_FAILURE);
        } else {
            printf("Attempting to execute: %s\n", command);
            execv(command, args);
            perror("Error");
            _exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
            printf("Command failed\n");
    } else {
        perror("Fork error");
    }
}

void executeCommandSequence(char *commands[], char *args[]) {
    int i = 0;
    while (commands[i] != NULL) {
        executeCommand(commands[i], args);
        i++;
    }
}

/**
 * handleInputError - Handles input error and prompts the user to continue.
 */
void handleInputError(void)
{
    printf("Error: Invalid input. Please try again.\n");
}

