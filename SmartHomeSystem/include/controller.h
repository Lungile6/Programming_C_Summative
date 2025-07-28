#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "sensor.h"

// Processes sensor data and decides which actuator to trigger
void process_sensor_data(Sensor* sensor);

#endif
