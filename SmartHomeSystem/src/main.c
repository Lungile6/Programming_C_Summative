#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "sensor.h"
#include "controller.h"
#include "logger.h"

#define MAX_RECORDS 50

volatile int record_count = 0;
volatile int stop_flag = 0;
pthread_mutex_t count_mutex;

// Thread to read sensor values and log them continuously
void* sensor_thread(void* arg) {
    Sensor* sensor = (Sensor*)arg;
    while (1) {
        if (stop_flag) break;
        read_sensor(sensor);        // Get new value
        log_sensor_data(sensor);    // Log to file
        pthread_mutex_lock(&count_mutex);
        record_count++;
        if (record_count >= MAX_RECORDS) {
            stop_flag = 1;
            pthread_mutex_unlock(&count_mutex);
            break;
        }
        pthread_mutex_unlock(&count_mutex);
        sleep(3);                   // Wait 3 seconds
    }
    return NULL;
}

// Thread to process sensor values and control actuators
void* controller_thread(void* arg) {
    Sensor* sensor = (Sensor*)arg;
    while (1) {
        if (stop_flag) break;
        process_sensor_data(sensor); // Take action if needed
        sleep(1);                    // React faster than sensor updates
    }
    return NULL;
}

int main() {
    // Create two sensors: temperature and motion
    Sensor* temp_sensor = create_sensor(1, "temperature");
    Sensor* motion_sensor = create_sensor(2, "motion");

    // Initialize mutex
    pthread_mutex_init(&count_mutex, NULL);

    // Threads for each sensor's reading and control
    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, NULL, sensor_thread, temp_sensor);
    pthread_create(&t2, NULL, sensor_thread, motion_sensor);
    pthread_create(&t3, NULL, controller_thread, temp_sensor);
    pthread_create(&t4, NULL, controller_thread, motion_sensor);

    // Wait for all threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    // Cleanup
    pthread_mutex_destroy(&count_mutex);
    destroy_sensor(temp_sensor);
    destroy_sensor(motion_sensor);

    printf("Program ended after %d records.\n", MAX_RECORDS);
    return 0;
}
