#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "student.h"

// Loads student records from file
int load_students(Student students[]) {
    FILE* file = fopen("records.txt", "r");
    if (!file) return 0;

    int count = 0;
    while (fscanf(file, "%d %49s %d %29s %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  students[count].course,
                  &students[count].grade) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}

// Saves all records to file
void save_students(Student students[], int count) {
    FILE* file = fopen("records.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].course,
                students[i].grade);
    }
    fclose(file);
}

// Add new student
void add_student(Student students[], int* count) {
    Student s;
    printf("Enter ID: "); scanf("%d", &s.id);
    printf("Enter Name: "); scanf("%s", s.name);
    printf("Enter Age: "); scanf("%d", &s.age);
    printf("Enter Course: "); scanf("%s", s.course);
    printf("Enter Grade: "); scanf("%f", &s.grade);

    students[*count] = s;
    (*count)++;
    printf("Student added!\n");
}

// Display all students
void display_students(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        print_student(students[i]);
    }
}

// Update student record by ID
void update_student(Student students[], int count) {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new name: "); scanf("%s", students[i].name);
            printf("Enter new age: "); scanf("%d", &students[i].age);
            printf("Enter new course: "); scanf("%s", students[i].course);
            printf("Enter new grade: "); scanf("%f", &students[i].grade);
            printf("Student updated.\n");
            return;
        }
    }
    printf("Student ID not found.\n");
}

// Delete student by ID
void delete_student(Student students[], int* count) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < (*count) - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student ID not found.\n");
}

// Search student by ID
void search_student(Student students[], int count) {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            print_student(students[i]);
            return;
        }
    }
    printf("Student ID not found.\n");
}
