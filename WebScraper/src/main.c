#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "scraper.h"
#include <curl/curl.h>

#define MAX_URLS 10
#define MAX_LENGTH 256

int main() {
    pthread_t threads[MAX_URLS];
    ThreadData data[MAX_URLS];
    int num_urls;

    printf("Enter number of URLs to scrape (max %d): ", MAX_URLS);
    scanf("%d", &num_urls);

    if (num_urls <= 0 || num_urls > MAX_URLS) {
        printf("Invalid number of URLs.\n");
        return 1;
    }

    getchar(); // clear newline after scanf

    for (int i = 0; i < num_urls; i++) {
        printf("Enter URL %d: ", i + 1);
        fgets(data[i].url, MAX_LENGTH, stdin);

        // Remove newline character
        size_t len = strlen(data[i].url);
        if (len > 0 && data[i].url[len - 1] == '\n') {
            data[i].url[len - 1] = '\0';
        }

        data[i].id = i + 1;
    }

    system("mkdir -p output");

    curl_global_init(CURL_GLOBAL_ALL);

    for (int i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, fetch_url, (void*)&data[i]);
    }

    for (int i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    curl_global_cleanup();

    printf("\nAll downloads complete. Check the 'output' folder.\n");
    return 0;
}
