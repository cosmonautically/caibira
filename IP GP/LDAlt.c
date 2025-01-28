#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a class that a student has passed.
typedef struct Class {
    char name[50];          // Name of the class
    struct Class* next;     // Pointer to the next class in the linked list
} Class;

// Structure to represent a student.
typedef struct Student {
    int id;                 // Student ID
    char firstName[50];     // First name
    char lastName[50];      // Last name
    Class* passedClasses;   // Pointer to the linked list of passed classes
} Student;

// Structure to manage the dynamic array of students.
typedef struct {
    Student* students;      // Pointer to the dynamic array of Student structs
    size_t size;            // Current number of students in the array
    size_t capacity;        // Maximum number of students before resizing is needed
} StudentDirectory;

// Function to initialize the student directory.
void initDirectory(StudentDirectory* directory, size_t initialCapacity) {
    directory->students = malloc(initialCapacity * sizeof(Student)); // Allocate memory for the array
    if (!directory->students) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    directory->size = 0;      // Initially, no students are in the directory
    directory->capacity = initialCapacity; // Set the initial capacity
}

// Function to resize the dynamic array when it's full.
void resizeDirectory(StudentDirectory* directory) {
    size_t newCapacity = directory->capacity * 2; // Double the capacity
    Student* newArray = realloc(directory->students, newCapacity * sizeof(Student)); // Reallocate memory
    if (newArray) {
        directory->students = newArray;
        directory->capacity = newCapacity;
    } else {
        fprintf(stderr, "Error: Unable to resize directory\n");
        exit(EXIT_FAILURE);
    }
}

// Function to add a new student to the directory.
void addStudent(StudentDirectory* directory, int id, const char* firstName, const char* lastName) {
    // Check if the array is full and needs resizing
    if (directory->size == directory->capacity) {
        resizeDirectory(directory);
    }

    // Add the new student at the end of the array
    Student* student = &directory->students[directory->size];
    student->id = id;
    strncpy(student->firstName, firstName, sizeof(student->firstName) - 1);
    strncpy(student->lastName, lastName, sizeof(student->lastName) - 1);
    student->passedClasses = NULL; // Initialize with no classes
    directory->size++; // Increment the size
}

// Function to remove a student from the directory by their ID.
void removeStudent(StudentDirectory* directory, int id) {
    for (size_t i = 0; i < directory->size; i++) {
        if (directory->students[i].id == id) {
            // Free the linked list of passed classes
            Class* current = directory->students[i].passedClasses;
            while (current) {
                Class* temp = current;
                current = current->next;
                free(temp);
            }

            // Shift the remaining students to fill the gap
            for (size_t j = i; j < directory->size - 1; j++) {
                directory->students[j] = directory->students[j + 1];
            }
            directory->size--; // Decrement the size
            return;
        }
    }
    fprintf(stderr, "Student with ID %d not found.\n", id);
}

// Function to add a passed class to a student.
void addClass(Student* student, const char* className) {
    Class* newClass = malloc(sizeof(Class)); // Allocate memory for the new class
    if (!newClass) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newClass->name, className, sizeof(newClass->name) - 1);
    newClass->next = student->passedClasses; // Insert at the head of the list
    student->passedClasses = newClass;
}

// Function to print all students in the directory.
void printDirectory(const StudentDirectory* directory) {
    for (size_t i = 0; i < directory->size; i++) {
        const Student* student = &directory->students[i];
        printf("ID: %d, Name: %s %s\n", student->id, student->firstName, student->lastName);
        printf("  Passed Classes:\n");
        Class* current = student->passedClasses;
        while (current) {
            printf("    - %s\n", current->name);
            current = current->next;
        }
    }
}

// Function to clean up and free all allocated memory.
void freeDirectory(StudentDirectory* directory) {
    for (size_t i = 0; i < directory->size; i++) {
        Class* current = directory->students[i].passedClasses;
        while (current) {
            Class* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(directory->students); // Free the student array
}

int main() {
    StudentDirectory directory;
    initDirectory(&directory, 2); // Initialize the directory with an initial capacity of 2

    addStudent(&directory, 1, "John", "Doe");
    addStudent(&directory, 2, "Jane", "Smith");

    addClass(&directory.students[0], "Math");
    addClass(&directory.students[0], "History");
    addClass(&directory.students[1], "Science");

    printf("Student Directory:\n");
    printDirectory(&directory);

    removeStudent(&directory, 1); // Remove John Doe
    printf("\nAfter removing John Doe:\n");
    printDirectory(&directory);

    freeDirectory(&directory); // Clean up all allocated memory
    return 0;
}
