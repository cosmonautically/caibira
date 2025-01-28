#ifndef STUDMAN
#define STUDMAN
#include "student.h"

/*In this file we will define students' managers. A student manager allows to manage groups of AUC students.
A student manager (studman) is a mutable collection of students (see student.h) where students can be added.
Moreover the manager offers various functionalities to retrieve data about students.
*/

typedef struct studManInner * studman;{

}student;



/*EFFECTS: Creates a new empty studman and returns it. 
  	   StartingID will be the first ID assigned to students in this studman.*/
studman newStudMan(int startingID);
  struct student->id= malloc(sizeof(struct student->id));


/*EFFECTS: Creates and adds a new student with the given data to sm. It also assigns 
           an ID to the student and returns it. The IDs will be assigned progressively 
	   starting from startingID (see newStudMan), i.e., the first student will have ID 
	   startingID the second startingID+1 and so on. */
int  addStudent(studman sm, char * name, char * surname, int year);


/*EFFECTS: Returns the number of students in sm.*/
int getStudentsNum(studman sm);


/*EFFECT: Returns the name of the student in sm with ID studentID. 
 	  If there is no such student returns "NONE"*/
char * getName(studman sm, int studentID);

/*EFFECT: Returns the surname of the student in sm with ID studentID. 
 	  If there is no such student returns "NONE"*/
char * getSurname(studman sm, int studentID);

/*EFFECT: Returns the year of enrollment of the student in sm with ID studentID. 
    	  If there is no such student returns -1*/
int getYear(studman sm, int studentID);

/*EFFECT: Adds the last passed course to the student with ID studentID. 
 	  If there is no such a student it does not do anything.*/
void addCourseToStudent(studman sm, int studentID, char * courseName);

/*EFFECT: Returns an array of the courses that the student with studentID 
 	  passed in the order in which they were passed (from older to newer).
          If there is no student with the given studentID returns NULL. 
          Note that the array must be deallocated by the caller.*/
char**  getStudentPassedCourses(studman sm, int studentID);


/*EFFECT: Returns the number of courses passed by the student with ID studentID.
          If there is no such a student returns -1 */
int  getNumberStudentPassedCourses(studman sm, int studentID);


/*EFFECT: Returns the studentID of the student with the given surname. 
          If there is no such a student returns -1, if there are more
          than one students with the same surname returns -2.*/
int getStudentsBySurname(studman sm, char * surname);

/*EFFECT: Frees the space used to store sm. Has no effects if s is NULL.*/
void freeStudman(studman sm);

#endif
