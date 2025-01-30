#ifndef STUDMAN
#define STUDMAN

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*In this file we will define students' managers. A student manager allows to manage groups of AUC students.
A student manager hi (students) is a mutable collection of students (see student.h) where students can be added.
Moreover the manager offers various functionalities to retrieve data about students.
*/

// structure to manage the dynamic array of students.
struct studManInner {
    student* students;      // pointer to the dynamic array of Student structs
    int size;            // current number of students in the array**
    int capacity;        // maximum number of students before resizing is needed
    int startingID;     //starting ID
};

typedef struct studManInner * studman;

// initialize the student directory.
void initDirectory(studman sm, int initialCapacity) {
    sm->students = malloc(initialCapacity * sizeof(student)); // allocate memory for the array
    if (!sm->students) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    sm->size = 0;      // initially, no students are in the directory
    sm->capacity = initialCapacity; // set the initial capacity
}

// resize the dynamic array when it's full.
void resizeDirectory(studman sm) {
    int newCapacity = sm->capacity * 2; // double the capacity
    student* newArray = realloc(sm->students, newCapacity * sizeof(student)); // reallocate memory
    if (newArray) {
        sm->students = newArray;
        sm->capacity = newCapacity;
    } else {
        fprintf(stderr, "Error: Unable to resize sm\n");
        exit(EXIT_FAILURE);
    }
}


/*EFFECTS: Creates a new empty studentdirectory and returns it. 
  	   StartingID will be the first ID assigned to students in this students.*/
studman newStudMan(int startingID){
    studman sm = malloc(sizeof(struct studManInner));
    initDirectory(sm, 10);
    sm->startingID=startingID;
    return sm;
}

/*EFFECTS: Creates and adds a new student with the given data to sm. It also assigns 
           an ID to the student and returns it. The IDs will be assigned progressively 
	   starting from startingID (see newstudents), i.e., the first student will have ID 
	   startingID the second startingID+1 and so on. */
int addStudent(studman sm, char * name, char * surname, int year){
    student student = newStudent(name, surname, (sm->startingID+sm->size), year);
	
    if (sm->size == sm->capacity) { //check if array is full > resize
        resizeDirectory(sm);
    }
    
    // add student at end of array
	student = sm->students[sm->size];
	sm->size++; //increase size 
    freeStudent(student);
    return sm->size + sm->startingID;
}

/*EFFECTS: Returns the number of students in sm.*/
int getStudentsNum(studman sm){
    return sm->size;
}

/*EFFECT: Returns the name of the student in sm with ID studentID. 
 	  If there is no such student returns "NONE"*/
char * getName(studman sm, int studentID){
    student s = sm->students[studentID-sm->startingID];
    return getStudentName(s);
	
}

/*EFFECT: Returns the surname of the student in sm with ID studentID. 
 	  If there is no such student returns "NONE"*/
char * getSurname(studman sm, int studentID){
    student s = sm->students[studentID-sm->startingID];
    return getStudentSurname(s);
   
    }

/*EFFECT: Returns the year of enrollment of the student in sm with ID studentID. 
    	  If there is no such student returns -1*/
int getYear(studman sm, int studentID){
    student s = sm->students[studentID-sm->startingID];
    return getStudentYear(s);
    }

/*EFFECT: Adds the last passed course to the student with ID studentID. 
 	  If there is no such a student it does not do anything.*/
void addCourseToStudent(studman sm, int studentID, char * courseName) {
    student s = sm->students[studentID-sm->startingID];
    addLastPassedCourse(s, courseName);
}

/*EFFECT: Returns an array of the courses that the student with studentID 
 	  passed in the order in which they were passed (from older to newer).
          If there is no student with the given studentID returns NULL. 
          Note that the array must be deallocated by the caller.*/
char**  getStudentPassedCourses(studman sm, int studentID){
    student s = sm->students[studentID-sm->startingID];
    return getPassedCourses(s);
    }

/*EFFECT: Returns the number of courses passed by the student with ID studentID.
          If there is no such a student returns -1 */
int  getNumberStudentPassedCourses(studman sm, int studentID) {
    student s = sm->students[studentID-sm->startingID];
    return getNumberOfPassedCourses(s);
}


/*EFFECT: Returns the studentID of the student with the given surname. 
          If there is no such a student returns -1, if there are more
          than one students with the same surname returns -2.*/
int getStudentsBySurname(studman sm, char * surname){
    student s;
    for(int i=0;i<sm->size-1;i++){
        if (strcmp(getStudentSurname(sm->students[i]), surname) == 0) {
        s = sm->students[i];
        }
    }
    return getStudentId(s);
    }

/*EFFECT: Frees the space used to store sm. Has no effects if s is NULL.*/
void freeStudman(studman sm) {
    free(sm);
}

#endif