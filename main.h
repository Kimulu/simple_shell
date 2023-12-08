#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int isInteractiveMode(void);
void displayPrompt(void);
void executeCommand(char *command, char *args[]);
void handleInputError(void);
void runShellScripts(void);

#endif
