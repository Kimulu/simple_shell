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
void executeCommand(char *command)
{
	pid_t pid;
	char *token = strtok(command, " ");

	if (token == NULL)
	{
		handleInputError();
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		char **args = malloc(2 * sizeof(char *));

		if (args == NULL)
		{
			perror("Error allocating memory");
			_exit(EXIT_FAILURE);
		}
		args[0] = token;
		args[1] = NULL;
		execvp(token, args);
		perror("Error");
		_exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			printf("Command failed\n");

		fflush(stdout);
	}
	else
	{
		perror("Fork error");
	}
}

/**
 * handleInputError - Handles input error and prompts the user to continue.
 */
void handleInputError(void)
{
	printf("Error: Invalid input. Please try again.\n");
}

/**
 * runShellScripts - Runs shell scripts in non-interactive mode.
 */
void runShellScripts(void)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *scriptPath = "/path/to/your/script.sh";

		if (execlp("sh", "sh", scriptPath, NULL) == -1)
		{
			perror("Error executing shell script");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
			printf("executed success with exit status %d\n", WEXITSTATUS(status));
		else
			printf("Shell script execution failed\n");
	}
	else
	{
		perror("Fork error");
	}
}

