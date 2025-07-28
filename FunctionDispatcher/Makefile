CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = src/main.o src/dispatcher.o src/fileops.o

all: dispatcher

dispatcher: $(OBJ)
	$(CC) $(CFLAGS) -o dispatcher $(OBJ)

clean:
	rm -f src/*.o dispatcher sample.txt
