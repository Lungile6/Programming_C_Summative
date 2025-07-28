#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "scraper.h"
#include <pthread.h>

// Callback for writing data from curl to file
size_t write_to_file(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Thread function to fetch and save URL content
void* fetch_url(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    // Create output filename
    char filename[64];
    snprintf(filename, sizeof(filename), "output/page_%d.html", data->id);

    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to create output file");
        pthread_exit(NULL);
    }

    CURL* curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Curl init failed\n");
        fclose(file);
        pthread_exit(NULL);
    }

    curl_easy_setopt(curl, CURLOPT_URL, data->url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_file);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);  // Follow redirects

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Thread %d: Failed to fetch URL: %s\n", data->id, curl_easy_strerror(res));
    } else {
        printf("Thread %d: Successfully saved %s\n", data->id, data->url);
    }

    curl_easy_cleanup(curl);
    fclose(file);
    pthread_exit(NULL);
}
