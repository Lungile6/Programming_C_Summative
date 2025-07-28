#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "executor.h"
#include "parser.h"

// Check for redirection
void handle_redirection(char** args) {
    for (int i = 0; args[i]; i++) {
        if (strcmp(args[i], "<") == 0) {
            int fd = open(args[i + 1], O_RDONLY);
            dup2(fd, STDIN_FILENO);
            close(fd);
            args[i] = NULL;
        } else if (strcmp(args[i], ">") == 0) {
            int fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[i] = NULL;
        }
    }
}

// Check and handle pipes
void handle_pipe(char* input_line) {
    char* cmd1 = strtok(input_line, "|");
    char* cmd2 = strtok(NULL, "|");

    if (cmd2 == NULL) {
        // No pipe; run normally
        char** args = tokenize_input(cmd1);
        if (args[0] != NULL) {
            pid_t pid = fork();
            if (pid == 0) {
                handle_redirection(args);
                execvp(args[0], args);
                perror("execvp failed");
                exit(1);
            } else {
                wait(NULL);
            }
        }
        free_tokens(args);
    } else {
        // Handle piping
        int pipefd[2];
        pipe(pipefd);

        pid_t pid1 = fork();
        if (pid1 == 0) {
            // First command writes to pipe
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);

            char** args1 = tokenize_input(cmd1);
            handle_redirection(args1);
            execvp(args1[0], args1);
            perror("execvp failed");
            exit(1);
        }

        pid_t pid2 = fork();
        if (pid2 == 0) {
            // Second command reads from pipe
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[1]);
            close(pipefd[0]);

            char** args2 = tokenize_input(cmd2);
            handle_redirection(args2);
            execvp(args2[0], args2);
            perror("execvp failed");
            exit(1);
        }

        // Parent closes pipe and waits
        close(pipefd[0]);
        close(pipefd[1]);
        wait(NULL);
        wait(NULL);
    }
}

// Entry point for executing a command
void execute_command(char* input_line) {
    // Handle built-in command
    if (strncmp(input_line, "exit", 4) == 0) {
        printf("Exiting MiniShell...\n");
        exit(0);
    }

    // Check for pipe
    if (strchr(input_line, '|')) {
        handle_pipe(input_line);
    } else {
        char** args = tokenize_input(input_line);
        if (args[0] != NULL) {
            pid_t pid = fork();
            if (pid == 0) {
                handle_redirection(args);
                execvp(args[0], args);
                perror("execvp failed");
                exit(1);
            } else {
                wait(NULL);
            }
        }
        free_tokens(args);
    }
}
