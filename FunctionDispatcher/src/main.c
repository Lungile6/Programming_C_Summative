#include <stdio.h>
#include <stdlib.h>
#include "dispatcher.h"

int main() {
    const char* filename = "sample.txt";
    int choice;

    do {
        printf("\n--- Dynamic Function Dispatcher ---\n");
        printf("1. Add Data to File\n");
        printf("2. Count Lines in File\n");
        printf("3. Count Characters in File\n");
        printf("4. Convert to UPPERCASE\n");
        printf("5. Convert to lowercase\n");
        printf("6. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting...\n");
            break;
        }

        dispatch(choice, filename);

    } while (choice != 6);

    return 0;
}
