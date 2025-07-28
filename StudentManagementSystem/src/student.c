#include <stdio.h>
#include "student.h"

// Displays a student record
void print_student(Student s) {
    printf("ID: %d | Name: %s | Age: %d | Course: %s | Grade: %.2f\n",
           s.id, s.name, s.age, s.course, s.grade);
}
