#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

// Splits input string into tokens (space-separated)
char** tokenize_input(char* input) {
    char** tokens = malloc(64 * sizeof(char*));
    int i = 0;
    char* token = strtok(input, " \n");

    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " \n");
    }
    tokens[i] = NULL;
    return tokens;
}

// Frees allocated token array (not strings, which are part of input)
void free_tokens(char** tokens) {
    free(tokens);
}
