#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

#define MAX_INPUT 1024

extern char **environ;
void deallocate_tokens(char **tokens);
char **tokenize_command(char *str, const char *d);
void find_path(char **pathname);
char **tokenize_directories(char *path_directories, const char *d);
void show_prompt(void);
ssize_t read_input(char **line_command, size_t *length);
void getline_errors(ssize_t read_characters, char *line_pointer);
void remove_newline(char *command_line, ssize_t read_characters);
void execute_command(char **tokens);
char *_getenv(const char *name);


#endif
