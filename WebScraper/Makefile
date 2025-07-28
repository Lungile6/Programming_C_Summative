CC = gcc
CFLAGS = -Wall -lcurl -lpthread -Iinclude
OBJ = src/main.o src/scraper.o

all: scraper

scraper: $(OBJ)
	$(CC) $(CFLAGS) -o scraper $(OBJ)

clean:
	rm -f src/*.o scraper
	rm -rf output/
