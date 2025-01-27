#ifndef STUD
#define STUD

/*OVERVIEW: This is the interface for a student data structure. 
	    A student should have the following attributes:
		-Name: A string of maximum 10 char
		-Surname: A string of maximum 10 char
		-Id: A number which identifies a student
		-Year: the year in which the student enrolled for the first time
		-Passed Curses: a sequence of strings which stores 
				the names of the courses that the student 
				passed so far in the order in which they were taken*/

typedef struct studentInner * student{


/*EFFECTS: Creates a new student with the given data and returns it*/
student newStudent(char * name, char * surname, int id,  int year);
	

/*EFFECT: Returns the name of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentName(student s);

/*EFFECT: Returns the surname of the student s. 
          If s is NULL it returns "NONE".*/
char * getStudentSurname(student s);

/*EFFECT: Returns the id of the student s. 
          If s is NULL it returns -1.*/
int getStudentId(student s);

/*EFFECT: Returns the year in which the student s enrolled. 
	  If s is NULL it returns -1.*/
int getStudentYear(student s);

/*EFFECT: Returns an array of the courses that the student passed in 
	  the order in which they were passed (from older to newer).
	  If s is NULL it returns NULL. 
	  Note that the array must be deallocated by the caller.*/
char** getPassedCourses(student s);

/*EFFECT: Returns the number of the courses that the student passed.
If s is NULL returns -1.*/

int getNumberOfPassedCourses(student s);

/*EFFECT: Adds courseName to the courses passed by the student s*/
void addLastPassedCourse(student s, char* courseName);


/*EFFECT: Frees the space used to store s. 
          Has no effects if s is NULL.*/
void freeStudent(student s);

#endif
