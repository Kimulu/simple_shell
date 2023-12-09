
#include "main.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        // Interactive mode
        interactive_mode();
    } else if (argc == 2) {
        // Batch mode
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("hsh");
            exit(EXIT_FAILURE);
        }

        batch_mode(file);
        fclose(file);
    } else {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}


