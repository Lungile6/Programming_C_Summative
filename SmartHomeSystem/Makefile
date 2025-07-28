CC=gcc
CFLAGS=-Wall -pthread -Iinclude
OBJ=src/main.o src/sensor.o src/controller.o src/actuator.o src/logger.o

# Default target to compile everything
all: smarthome

# Link all object files into final executable
smarthome: $(OBJ)
	$(CC) $(CFLAGS) -o smarthome $(OBJ)

# Clean build artifacts
clean:
	rm -f src/*.o smarthome
