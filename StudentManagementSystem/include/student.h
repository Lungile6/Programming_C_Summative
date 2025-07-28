#ifndef STUDENT_H
#define STUDENT_H

// Structure to store student information
typedef struct {
    int id;
    char name[50];
    int age;
    char course[30];
    float grade;
} Student;

// Function declarations
void print_student(Student s);

#endif
