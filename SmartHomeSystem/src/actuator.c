#include <stdio.h>
#include "actuator.h"

// Simulates light control
void control_light(int on) {
    printf("Light is %s\n", on ? "ON" : "OFF");
}

// Simulates alarm control
void sound_alarm(int on) {
    printf("Alarm is %s\n", on ? "ON" : "OFF");
}
