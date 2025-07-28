#ifndef SENSOR_H
#define SENSOR_H

// Structure to store sensor details
typedef struct {
    int id;              // Unique sensor ID
    char type[20];       // Type of sensor (e.g., "temperature", "motion")
    float value;         // Sensor value (e.g., 22.5°C, 0/1 for motion)
} Sensor;

// Creates and initializes a sensor dynamically
Sensor* create_sensor(int id, const char* type);

// Reads (simulated) value from the sensor
void read_sensor(Sensor* sensor);

// Frees dynamically allocated memory for the sensor
void destroy_sensor(Sensor* sensor);

#endif
