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



/*EFFECTS: Creates a new student with the given data and returns it*/
 newStudent(char * name, char * surname, int id,  int year){ //CAN WE CHANGE ARGUMENTS
	if (directory->size == directory->capacity) { //check if array is full > resize
		resizeDirectory(directory);
	}

// add student at end of array
Student* student = &directory->students[directory->size]; // **node creation need not be array specific
student->id = id;
strncpy(student->name, name, sizeof(student->name) - 1);
strncpy(student->surname, surname, sizeof(student->surname) - 1);
student->passedClasses = NULL;
directory->size++; //increase size 
}

/*EFFECT: Returns the name of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentName(student s){
	if (s.name !=NULL){
		return s.name;
	}
	else return "NONE";
}

/*EFFECT: Returns the surname of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentSurname(Student s){
	if (s.surname !=NULL){
		return s.surname;
	}
	else return "NONE";
}

/*EFFECT: Returns the id of the student s. 
          If s is NULL it returns -1.*/
int getStudentId(Student s){
	if (s.id !=NULL){
		return s.id;}
	else return -1;
}

/*EFFECT: Returns the year in which the student s enrolled. 
	  If s is NULL it returns -1.*/
int getStudentYear(Student s){
	if (s.year !=NULL){
		return s.year;}
	else return -1;
}

/*EFFECT: Returns an array of the courses that the student passed in 
	  the order in which they were passed (from older to newer).
	  If s is NULL it returns NULL. 
	  Note that the array must be deallocated by the caller.*/
char** getPassedCourses(Student s){

	int size = getNumberOfPassedCourses(s);
	int i = 0;
	char passarray[] = malloc(size*sizeof(char[30]));
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
	return *passarray;
}

/*EFFECT: Returns the number of the courses that the student passed.
If s is NULL returns -1.*/
int getNumberOfPassedCourses(Student s){

	if (!s.passedClasses) {
		printf("Student %s %s has not passed any classes.\n", s.name, s.surname);
        return;
	}

	printf("Classes passed by %s %s:\n", s.name, s.surname);

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
void addLastPassedCourse(Student* s, char* courseName) {
	Class* newClass = malloc(sizeof(Class));
	if (!newClass) {
		printf("Error: Memory allocation failed.\n");
		exict(EXIT_FAILURE);
	}
	strncpy(newClass->name, courseName, sizeof(newClass->name) - 1);
	newClass->next = s->passedClasses;
	s->passedClasses = newClass;
}

/*EFFECT: Frees the space used to store s. 
          Has no effects if s is NULL.*/
void freeStudent(Student s);


void main () {


}

#endif
