#include "main.h"

/**
<<<<<<< HEAD
 * print_prompt - Print shell prompt.
 */
void print_prompt(void)
=======
* main - main entry point
* @argc: argument count
* @argv: command line arguments
* Return: 0
*/

int main(int argc, char *argv[])
>>>>>>> 5bada745feb483f0c12735b6b025455aa93994e8
{
    if (isatty(STDIN_FILENO))
        printf("Shell-Prompt> ");
}

<<<<<<< HEAD
/**
 * handle_exit - Handle the exit command.
 * @line: Input line.
 */
bool handle_exit(char *line)
{
    if (strcmp(line, "exit") == 0)
    {
        free(line);
        return true;
    }
    return false;
}

/**
 * process_command - Process the entered command.
 * @line: Input line.
 * @counter: Command counter.
 * @argv: Command line arguments.
 */
void process_command(char *line, size_t counter, char *argv[])
=======
while (true)
{
if (isatty(STDIN_FILENO))
show_prompt();
fflush(stdout);
char_read = read_input(&pointer_to_line, &line_size);
++counter;
getline_errors(char_read, pointer_to_line);
remove_newline(pointer_to_line, char_read);
if (*pointer_to_line == '\0')
continue;
if (strcmp(pointer_to_line, "exit") == 0)
>>>>>>> 5bada745feb483f0c12735b6b025455aa93994e8
{
    char **tokens;

    if (*line == '\0' || !(tokens = tokenize_command(line, " ")))
        return;

    if (access(tokens[0], X_OK) == -1 && (find_path(&tokens[0]), access(tokens[0], X_OK) == -1))
        fprintf(stderr, "%s: %lu: %s: not found\n", argv[0], counter, tokens[0]);
    else
        execute_command(tokens);

    free(line);
    deallocate_tokens(tokens);
}
<<<<<<< HEAD

/**
 * main - Main entry point.
 * @argc: Argument count.
 * @argv: Command line arguments.
 * Return: 0.
 */
int main(int argc __attribute__((unused)), char *argv[])
=======
if (argc > 1 && strcmp(argv[1], "env") == 0)
_printenv();
command_tokens = tokenize_command(pointer_to_line, " ");
if (command_tokens == NULL)
continue;
if (access(command_tokens[0], X_OK) == -1)
{
find_path(&command_tokens[0]);
if (command_tokens != NULL && access(command_tokens[0], X_OK) == -1)
>>>>>>> 5bada745feb483f0c12735b6b025455aa93994e8
{
    char *line = NULL;
    size_t size = 0, counter = 0;
    ssize_t read_chars;

    while (true)
    {
        print_prompt();
        fflush(stdout);

        read_chars = read_input(&line, &size);
        getline_errors(read_chars, line);
        remove_newline(line, read_chars);

        if (handle_exit(line))
            return 0;

        process_command(line, ++counter, argv);
        line = NULL;
    }
}

