#include <string.h>
#include "controller.h"
#include "actuator.h"

// Decides action based on sensor type and value
void process_sensor_data(Sensor* sensor) {
    // If it's a temperature sensor and value > 25°C, turn on the light
    if (strcmp(sensor->type, "temperature") == 0 && sensor->value > 25.0)
        control_light(1);

    // If it's a motion sensor and motion is detected (value == 1), sound alarm
    else if (strcmp(sensor->type, "motion") == 0 && sensor->value == 1)
        sound_alarm(1);
}
