#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/*Function to display a prompt for the user in interactive mode*/
void displayPrompt() {
    printf("$ "); /*Customize the prompt as needed*/
    fflush(stdout); /*Ensure the prompt is displayed immediately*/
}

int isInteractiveMode() {
    return isatty(fileno(stdin));
}

/* Function to execute the provided command */
void executeCommand(char *command) {
    /* Tokenize the input to get the first word as the command */
    char *token = strtok(command, " ");

    if (token != NULL) {
        /* Create a child process */
        pid_t pid = fork();

        if (pid == 0) {
            /* Child process */
            char **args = malloc(2 * sizeof(char *));
            if (args == NULL) {
                perror("Error allocating memory");
                _exit(EXIT_FAILURE);
            }

            args[0] = token;
            args[1] = NULL;

            /* Execute the command using execvp */
            if (execvp(token, args) == -1) {
                /* Handle command not found */
                perror("Error");
                _exit(EXIT_FAILURE);
            }

            free(args);
        } else if (pid > 0) {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                printf("Command executed successfully with exit status %d\n", WEXITSTATUS(status));
            } else {
                printf("Command execution failed\n");
            }
        } else {
            /* Fork error */
            perror("Fork error");
        }
    } else {
        handleInputError(); /* Handle the case where no command is provided */
    }
}

/*Function to handle input error and prompt the user to continue*/
void handleInputError() {
    printf("Error: Invalid input. Please try again.\n");
}

/*Function to run shell scripts in non-interactive mode*/
void runShellScripts() {
    /*Placeholder logic for running shell scripts*/
    /*For example, you can run a specific script or commands*/

    pid_t pid = fork();

    if (pid == 0) {
        
        char *scriptPath = "/path/to/your/script.sh";

        
        if (execlp("sh", "sh", scriptPath, NULL) == -1) {
            perror("Error executing shell script");
            _exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Shell script executed successfully with exit status %d\n", WEXITSTATUS(status));
        } else {
            printf("Shell script execution failed\n");
        }
    } else {
        
        perror("Fork error");
    }
}
