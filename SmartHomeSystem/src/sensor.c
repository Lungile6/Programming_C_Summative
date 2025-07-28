#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sensor.h"

// Dynamically allocates memory and initializes a sensor
Sensor* create_sensor(int id, const char* type) {
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    sensor->id = id;
    strcpy(sensor->type, type);
    sensor->value = 0.0; // Initial dummy value
    return sensor;
}

// Simulates reading data from a sensor
void read_sensor(Sensor* sensor) {
    srand(time(NULL) + sensor->id); // Unique seed per sensor

    if (strcmp(sensor->type, "temperature") == 0)
        sensor->value = 15.0 + rand() % 15;  // Random temperature 15–30°C
    else if (strcmp(sensor->type, "motion") == 0)
        sensor->value = rand() % 2;          // 0 or 1 (motion/no motion)
}

// Frees memory allocated for sensor
void destroy_sensor(Sensor* sensor) {
    free(sensor);
}
