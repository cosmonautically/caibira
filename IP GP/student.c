#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STUD
#define STUD


// structure to represent a class that a student has passed.
typedef struct Class {
    char name[50];          // name of the class
    struct Class* next;     // pointer to the next class in the linked list
} Class;

// structure to represent a student.
typedef struct Student {
    int id;                 // student ID
    char name[10];     // first name
    char surname[10];      // last name
    Class* passedClasses;   // pointer to the linked list passedClasses
} Student;

// structure to manage the dynamic array of students.
typedef struct {
    Student* students;      // pointer to the dynamic array of Student structs
    size_t size;            // current number of students in the array
    size_t capacity;        // maximum number of students before resizing is needed
} StudentDirectory;

// initialize the student directory.
void initDirectory(StudentDirectory* directory, size_t initialCapacity) {
    directory->students = malloc(initialCapacity * sizeof(Student)); // allocate memory for the array
    if (!directory->students) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    directory->size = 0;      // initially, no students are in the directory
    directory->capacity = initialCapacity; // set the initial capacity
}

// resize the dynamic array when it's full.
void resizeDirectory(StudentDirectory* directory) {
    size_t newCapacity = directory->capacity * 2; // double the capacity
    Student* newArray = realloc(directory->students, newCapacity * sizeof(Student)); // reallocate memory
    if (newArray) {
        directory->students = newArray;
        directory->capacity = newCapacity;
    } else {
        fprintf(stderr, "Error: Unable to resize directory\n");
        exit(EXIT_FAILURE);
    }
}


/*OVERVIEW: This is the interface for a student data structure. 
	    A student should have the following attributes:
		-Name: A string of maximum 10 char
		-Surname: A string of maximum 10 char
		-Id: A number which identifies a student
		-Year: the year in which the student enrolled for the first time
		-Passed Courses: a sequence of strings which stores 
				the names of the courses that the student 
				passed so far in the order in which they were taken*/

/*EFFECTS: Creates a new student with the given data and returns it*/
 newStudent(StudentDirectory * directory, char * name, char * surname, int id,  int year){
	if (directory->size == directory->capacity) { //check if array is full > resize
		resizeDirectory(directory);
	}

// add student at end of array
Student* student = &directory->students[directory->size];
student->id = id;
strncpy(student->name, name, sizeof(student->name) - 1);
strncpy(student->surname, surname, sizeof(student->surname) - 1);
student->passedClasses = NULL;
directory->size++; //increase size 
}




/*EFFECT: Returns the name of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentName(Student s){
	if (student[s] !=NULL){
		return student[s]->name;
	}
	else return "NONE";
}

/*EFFECT: Returns the surname of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentSurname(Student s){
	if (student[s] !=NULL){
		return student[s]->surname;
	}
	else return "NONE";
}

/*EFFECT: Returns the id of the student s. 
          If s is NULL it returns -1.*/
int getStudentId(Student s){
	if (student[s] !=NULL){
		return student[s]->id;}
	else return -1;
}

/*EFFECT: Returns the year in which the student s enrolled. 
	  If s is NULL it returns -1.*/
int getStudentYear(Student s){
	if (student[s] !=NULL){
		return student[s]->name;}
	else return -1;
}

/*EFFECT: Returns an array of the courses that the student passed in 
	  the order in which they were passed (from older to newer).
	  If s is NULL it returns NULL. 
	  Note that the array must be deallocated by the caller.*/
char** getPassedCourses(Student s){
	if (student[s] !=NULL){
		return student[s]->passedcourses;}
	else return NULL;
}

/*EFFECT: Returns the number of the courses that the student passed.
If s is NULL returns -1.*/
int getNumberOfPassedCourses(Student s){
	struct passedcourses*head;
	struct passedcourses*tracer;	
	while (student[s]->passedcourses!=NULL){ //should it check passedcourses->tracer?
		//cycle through passed courses
		int numofcourses++;}
	return numofcourses;
}

/*EFFECT: Adds courseName to the courses passed by the student s*/
void addLastPassedCourse(Student s, char* courseName) {
	Class* newClass = malloc(sizeof(Class));
	if (!newClass) {
		printf("Error: Memory allocation failed.\n");
		exict(EXIT_FAILURE);
	}
	strncpy(newClass->name, courseName, sizeof(newClass->name) - 1);
	newClass->next = Student->passedClasses;
	Student->passedClasses = newClass;
}

/*EFFECT: Frees the space used to store s. 
          Has no effects if s is NULL.*/
void freeStudent(Student s);


void main () {


}

#endif
