#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int isInteractiveMode();
void displayPrompt();
void executeCommand(char *command);
void handleInputError();
void runShellScripts();

#endif
