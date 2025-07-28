#ifndef SCRAPER_H
#define SCRAPER_H

// Structure to pass URL and thread ID
typedef struct {
    char url[256];
    int id;
} ThreadData;

// Function executed by each thread
void* fetch_url(void* arg);

#endif
