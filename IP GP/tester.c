#include <stdio.h>
#include <stdlib.h>
#include "studentManager.h"
#define N 11

int main(void){
	//Get number of students to be inserted
	int studN=0;
	scanf("%d",&studN);

	
	int year;
	char ** names=malloc(studN*sizeof(char *));
	char ** surnames=malloc(studN*sizeof(char *));

	//initialises the student manager
	studman sm=newStudMan(100);

	//inserts studN many students in sm
	for(int i=0; i<studN; i++){
				names[i]=malloc(N*sizeof(char));
				surnames[i]=malloc(N*sizeof(char));

				scanf("%s",names[i]);
				scanf("%s",surnames[i]);
				scanf("%d",&year);

				addStudent(sm,names[i],surnames[i],year);
	}

	//Prints the students that were just inserted
	for(int i=0; i<studN; i++) printf("Name: %s Surname: %s Year: %d\n", getName(sm,100+i),getSurname(sm,100+i),getYear(sm,100+i));
	

	//for each student asks the courses to be inserted and inserts them
	char*** courses=malloc(studN*sizeof(char**));
	int * coursesNum=malloc(studN*sizeof(int));
	for(int j=0; j<studN; j++){
		//Asks how many courses we want to insert  
		scanf("%d",&coursesNum[j]);
		courses[j]=malloc(coursesNum[j]*sizeof(char*));
		for(int i=0;i<coursesNum[j];i++){
			courses[j][i]=malloc(N*sizeof(char));
			scanf("%s",courses[j][i]);
			addCourseToStudent(sm,100+j,courses[j][i]);
		}
	}
	
	//prints the courses of every student
	for(int j=0; j<studN; j++){
		char ** coursesA=getStudentPassedCourses(sm,100+j);
		printf("Student: %d\n", getStudentsBySurname(sm, getSurname(sm,100+j)));
		for(int i=0;i<getNumberStudentPassedCourses(sm,100+j);i++) printf("%s ",coursesA[i]);	
		printf("\n");
		printf("-----------------------\n");
		free(coursesA);
	}

	//frees everything
	for(int i=0; i<studN;i++){
		free(names[i]);
		free(surnames[i]);
	}
	freeStudman(sm);
	free(names);
	free(surnames);
	
	for(int j=0;j<studN;j++){
		for(int i=0;i<coursesNum[j];i++) free(courses[j][i]);
		free(courses[j]);
	}
	free(courses);
	free(coursesNum);

	return 0;
}
