#ifndef STUDMAN
#define STUDMAN

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*In this file we will define students' managers. A student manager allows to manage groups of AUC students.
A student manager hi (students) is a mutable collection of students (see student.h) where students can be added.
Moreover the manager offers various functionalities to retrieve data about students.
*/

typedef struct Class {
    char name[50];          // name of the class
    struct Class* next;     // pointer to the next class in the linked list
} Class;

// structure to represent a student.
typedef struct studentInner {
    int id;                 // student ID
    char name[10];     // first name
    char surname[10];      // last name
	int year;
    Class* passedClasses;   // pointer to the linked list passedClasses
} student;

// structure to manage the dynamic array of students.
typedef struct {
    student* students;      // pointer to the dynamic array of Student structs
    int size;            // current number of students in the array**
    int capacity;        // maximum number of students before resizing is needed
    int startingID;     //starting ID
} StudManInner;

// initialize the student directory.
void initDirectory(StudManInner* directory, size_t initialCapacity) {
    directory->students = malloc(initialCapacity * sizeof(student)); // allocate memory for the array
    if (!directory->students) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    directory->size = 0;      // initially, no students are in the directory
    directory->capacity = initialCapacity; // set the initial capacity
}

// resize the dynamic array when it's full.
void resizeDirectory(StudManInner* directory) {
    int newCapacity = directory->capacity *2; // double the capacity
    student* newArray = realloc(directory->students, newCapacity * sizeof(student)); // reallocate memory
    if (newArray) {
        directory->students = newArray;
        directory->capacity = newCapacity;
    } else {
        fprintf(stderr, "Error: Unable to resize directory\n");
        exit(EXIT_FAILURE);
    }
}


/*EFFECTS: Creates a new empty studentdirectory and returns it. 
  	   StartingID will be the first ID assigned to students in this students.*/
StudManInner* newstudentdirectory(StudManInner* directory, int startingID){
    if (directory->size == directory->capacity) { //check if array is full > resize
        resizeDirectory(directory);}
    directory->startingID=startingID;
    return directory;
}


/*EFFECTS: Creates and adds a new student with the given data to sm. It also assigns 
           an ID to the student and returns it. The IDs will be assigned progressively 
	   starting from startingID (see newstudents), i.e., the first student will have ID 
	   startingID the second startingID+1 and so on. */
int  addStudent(StudManInner *directory, char * name, char * surname, int startingID, int year){

	// add student at end of array
	student* student = &directory->students[directory->size];
	student->id = (startingID+directory->size);
	strncpy(student->name, name, sizeof(student->name) - 1);
	strncpy(student->surname, surname, sizeof(student->surname) - 1);
	student->passedClasses = NULL;
	directory->size++; //increase size 
	}


/*EFFECTS: Returns the number of students in sm.*/
int getStudentsNum(StudManInner sm){

}

/*EFFECT: Returns the name of the student in sm with ID studentID. 
 	  If there is no such student returns "NONE"*/
char * getName(StudManInner *directory, int studentID){
    student s;
	for (int i=0;i<directory->size;i++){
        if (directory->students[studentID-directory->startingID].id==studentID){
            s = directory->students[studentID-directory->startingID];
        }
    }
    getStudentName(s);
	
}


/*EFFECT: Returns the surname of the student in sm with ID studentID. 
 	  If there is no such student returns "NONE"*/
char * getSurname(StudManInner sm, int studentID);

/*EFFECT: Returns the year of enrollment of the student in sm with ID studentID. 
    	  If there is no such student returns -1*/
int getYear(StudManInner sm, int studentID);

/*EFFECT: Adds the last passed course to the student with ID studentID. 
 	  If there is no such a student it does not do anything.*/
void addCourseToStudent(StudManInner sm, int studentID, char * courseName);

/*EFFECT: Returns an array of the courses that the student with studentID 
 	  passed in the order in which they were passed (from older to newer).
          If there is no student with the given studentID returns NULL. 
          Note that the array must be deallocated by the caller.*/
char**  getStudentPassedCourses(StudManInner sm, int studentID);


/*EFFECT: Returns the number of courses passed by the student with ID studentID.
          If there is no such a student returns -1 */
int  getNumberStudentPassedCourses(StudManInner sm, int studentID);


/*EFFECT: Returns the studentID of the student with the given surname. 
          If there is no such a student returns -1, if there are more
          than one students with the same surname returns -2.*/
int getStudentsBySurname(StudManInner sm, char * surname);

/*EFFECT: Frees the space used to store sm. Has no effects if s is NULL.*/
void freestudents(StudManInner sm);

#endif
