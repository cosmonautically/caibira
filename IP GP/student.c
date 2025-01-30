#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STUD
#define STUD


/*OVERVIEW: This is the interface for a student data structure. 
	    A student should have the following attributes:
		-Name: A string of maximum 10 char
		-Surname: A string of maximum 10 char
		-Id: A number which identifies a student
		-Year: the year in which the student enrolled for the first time
		-Passed Courses: a sequence of strings which stores 
				the names of the courses that the student 
				passed so far in the order in which they were taken*/


typedef struct Class { // CLONE FROM STUDMAN.
    char name[50];          // name of the class
    struct Class* next;     // pointer to the next class in the linked list
} Class;

// structure to represent a student CLONE FROM STUDMAN
typedef struct studentInner {
    int id;                 // student ID
    char name[10];     // first name
    char surname[10];      // last name
	int year;
    Class* passedClasses;   // pointer to the linked list passedClasses
} student;



/*EFFECTS: Creates a new student with the given data and returns it*/
student newStudent(char * name, char * surname, int id,  int year){ //CAN WE CHANGE ARGUMENTS
	// if (directory->size == directory->capacity) { //check if array is full > resize
	// 	resizeDirectory(directory);
	// }

	// add student at end of array
	student* student = malloc(sizeof(student)); 
	student->year = year;
	student->id = id;
	strncpy(student->name, name, sizeof(student->name) - 1);
	strncpy(student->surname, surname, sizeof(student->surname) - 1);
	student->passedClasses = NULL;
	return *student;
}

int getNumberOfPassedCourses(student s);

/*EFFECT: Returns the name of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentName(student s){
	if (s.name != NULL){
		return strdup(s.name);
	}
	else return "NONE";
}

/*EFFECT: Returns the surname of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentSurname(student s){
	if (s.surname !=NULL){
		return strdup(s.surname);
	}
	else return "NONE";
}

/*EFFECT: Returns the id of the student s. 
          If s is NULL it returns -1.*/
int getStudentId(student s){
	return s.id;
}

/*EFFECT: Returns the year in which the student s enrolled. 
	  If s is NULL it returns -1.*/
int getStudentYear(student s){
	if (&s.year != NULL){
		return s.year;}
	else return -1;
}

/*EFFECT: Returns an array of the courses that the student passed in 
	  the order in which they were passed (from older to newer).
	  If s is NULL it returns NULL. 
	  Note that the array must be deallocated by the caller.*/
char** getPassedCourses(student s){

	int size = getNumberOfPassedCourses(s);
	int i = 0;
	char** passarray = (char**)malloc(size * sizeof(char*));
	for (int j = 0; j < size; j++) {
		passarray[j] = (char*)malloc(30 * sizeof(char));
	}
	Class* current = s.passedClasses;

	if (current == NULL){
		printf("Student %s %s has not passed any classes :c\n", s.name, s.surname);
		return NULL;
		}
	else {
		while (current != NULL) {
				passarray[i] = current->name;
				current = current->next;
				i++;
		}
	}

	return passarray;
}

/*EFFECT: Returns the number of the courses that the student passed.
If s is NULL returns -1.*/
int getNumberOfPassedCourses(student s){

	if (!s.passedClasses) {
		printf("Student %s %s has not passed any classes.\n", s.name, s.surname);
        return 0;
	}

	//printf("Classes passed by %s %s:\n", s.name, s.surname);

	int numofcourses;
	Class* current = s.passedClasses;

	while(current!=NULL){
		//cycle through passed course
		numofcourses++;
		current = current->next;
	}
	return numofcourses;
}

/*EFFECT: Adds courseName to the courses passed by the student s*/
void addLastPassedCourse(student s, char* courseName) {
	Class* newClass = malloc(sizeof(Class));
	if (!newClass) {
		printf("Error: Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	strncpy(newClass->name, courseName, sizeof(newClass->name) - 1);
	newClass->next = s.passedClasses;
	s.passedClasses = newClass;
}

/*EFFECT: Frees the space used to store s. 
          Has no effects if s is NULL.*/
void freeStudent(student s) {
	// free passed classes
	if (s.passedClasses != NULL) {
		Class* current = s.passedClasses;
		Class* next;
		while (current != NULL) {
			next = current->next;
			free(current);
			current = next;
		}
	}
}

#endif