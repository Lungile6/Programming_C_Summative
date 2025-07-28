#ifndef PARSER_H
#define PARSER_H

// Splits input into tokens
char** tokenize_input(char* input);

// Frees memory allocated for tokens
void free_tokens(char** tokens);

#endif
