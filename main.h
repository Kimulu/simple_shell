#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

extern char **environ;
void deallocate_tokens(char **tokens);
char **tokenize_command(char *str, const char *d);
void find_path(char **pathname);
ssize_t read_input(char **line_command, size_t *length);
void getline_errors(ssize_t read_characters, char *line_pointer);
void remove_newline(char *command_line, ssize_t read_characters);
void execute_command(char **tokens);
char *_getenv(const char *name);
void _printenv(char **env_var);
void process_command(char *line, size_t counter, char *argv[]);
void print_prompt(void);
bool handle_exit(char *line);
char *_strtok(char *string, const char *dm);


#endif
