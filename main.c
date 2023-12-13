#include "main.h"

/**
 * print_prompt - Print shell prompt.
 */
void print_prompt(void)
{
    if (isatty(STDIN_FILENO))
        printf("Shell-Prompt> ");
}

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

/**
 * main - Main entry point.
 * @argc: Argument count.
 * @argv: Command line arguments.
 * Return: 0.
 */
int main(int argc __attribute__((unused)), char *argv[])
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

