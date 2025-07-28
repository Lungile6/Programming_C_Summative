#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "executor.h"

int main() {
    char input_line[1024];

    while (1) {
        // Display shell prompt
        printf("MiniShell> ");
        fflush(stdout);

        // Read input
        if (fgets(input_line, sizeof(input_line), stdin) == NULL) {
            printf("\n");
            break; // EOF (Ctrl+D)
        }

        // Skip empty input
        if (strcmp(input_line, "\n") == 0)
            continue;

        // Execute the command
        execute_command(input_line);
    }

    return 0;
}
