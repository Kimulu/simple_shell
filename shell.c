#include "main.h"

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) { // Child process
        char *args[] = {command, NULL};
        if (execvp(args[0], args) == -1) {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("hsh");
    } else { // Parent process
        waitpid(pid, &status, 0);
    }
}

void interactive_mode() {
    char *input = NULL;
    size_t len = 0;

    while (1) {
        printf("$ ");
        if (getline(&input, &len, stdin) == -1) {
            perror("hsh");
            exit(EXIT_FAILURE);
        }

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            free(input);
            exit(EXIT_SUCCESS);
        }

        execute_command(input);

        free(input);
    }
}

void batch_mode(FILE *file) {
    char *input = NULL;
    size_t len = 0;

    while (getline(&input, &len, file) != -1) {
        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        execute_command(input);
    }

    free(input);
}

