#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "database.h"
#include "utility.h"

int main() {
    Student students[MAX_STUDENTS];
    int count = load_students(students);
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("6. Sort by Name\n");
        printf("7. Sort by Grade\n");
        printf("8. Save and Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(students, &count); break;
            case 2: display_students(students, count); break;
            case 3: update_student(students, count); break;
            case 4: delete_student(students, &count); break;
            case 5: search_student(students, count); break;
            case 6: sort_by_name(students, count); break;
            case 7: sort_by_grade(students, count); break;
            case 8: save_students(students, count); printf("Saved.\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 8);

    return 0;
}
