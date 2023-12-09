#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

void execute_command(char *command);
void interactive_mode();
void batch_mode(FILE *file);

#endif
