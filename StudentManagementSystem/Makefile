CC = gcc
CFLAGS = -Wall -Iinclude
OBJS = src/main.o src/student.o src/database.o src/utility.o

all: student_mgmt

student_mgmt: $(OBJS)
	$(CC) $(CFLAGS) -o student_mgmt $(OBJS)

clean:
	rm -f src/*.o student_mgmt records.txt
