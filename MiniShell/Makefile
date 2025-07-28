CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = src/main.o src/parser.o src/executor.o

all: minishell

minishell: $(OBJ)
	$(CC) $(CFLAGS) -o minishell $(OBJ)

clean:
	rm -f src/*.o minishell
