#ifndef DATABASE_H
#define DATABASE_H

#include "student.h"

#define MAX_STUDENTS 100

// CRUD operations
int load_students(Student students[]);
void save_students(Student students[], int count);

void add_student(Student students[], int* count);
void display_students(Student students[], int count);
void update_student(Student students[], int count);
void delete_student(Student students[], int* count);
void search_student(Student students[], int count);

#endif
