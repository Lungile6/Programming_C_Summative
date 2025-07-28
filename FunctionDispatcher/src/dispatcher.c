#include <stdio.h>
#include "dispatcher.h"
#include "fileops.h"

// Dispatch table of function pointers
void dispatch(int choice, const char* filename) {
    // Array of function pointers for each operation
    FunctionHandler handlers[] = {
        add_data,
        count_lines,
        count_characters,
        to_uppercase,
        to_lowercase
    };

    int num_functions = sizeof(handlers) / sizeof(FunctionHandler);

    if (choice >= 1 && choice <= num_functions) {
        handlers[choice - 1](filename);
    } else {
        printf("Invalid option.\n");
    }
}
