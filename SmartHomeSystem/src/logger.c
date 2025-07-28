#include <stdio.h>
#include <time.h>
#include "logger.h"

// Appends a sensor reading to a log file with timestamp
void log_sensor_data(Sensor* sensor) {
    FILE* file = fopen("logs/sensor_log.txt", "a");
    if (file) {
        time_t now = time(NULL);
        fprintf(file, "[%s] Sensor ID: %d, Type: %s, Value: %.2f\n",
                ctime(&now), sensor->id, sensor->type, sensor->value);
        fclose(file);
    }
}
