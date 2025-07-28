#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fileops.h"

// Adds data to file from user input
void add_data(const char* filename) {
    FILE* file = fopen(filename, "a");
    if (!file) {
        perror("File open failed");
        return;
    }

    char* buffer = (char*)malloc(256 * sizeof(char));
    printf("Enter data to append: ");
    getchar(); // consume newline
    fgets(buffer, 256, stdin);

    fprintf(file, "%s", buffer);
    fclose(file);
    free(buffer);
}

// Counts number of lines in the file
void count_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File open failed");
        return;
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') count++;
    }

    fclose(file);
    printf("Total lines: %d\n", count);
}

// Counts number of characters in the file
void count_characters(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File open failed");
        return;
    }

    int count = 0;
    while (fgetc(file) != EOF) count++;

    fclose(file);
    printf("Total characters: %d\n", count);
}

// Converts file content to uppercase and prints it
void to_uppercase(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File open failed");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    for (int i = 0; buffer[i]; i++)
        buffer[i] = toupper(buffer[i]);

    printf("Uppercase content:\n%s\n", buffer);

    fclose(file);
    free(buffer);
}

// Converts file content to lowercase and prints it
void to_lowercase(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File open failed");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    for (int i = 0; buffer[i]; i++)
        buffer[i] = tolower(buffer[i]);

    printf("Lowercase content:\n%s\n", buffer);

    fclose(file);
    free(buffer);
}
