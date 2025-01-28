#include <stdio.h>
#include <stdlib.h>

typedef struct studentInner{
	char name[10];
	char surname[10];
	int id;
	int year;
	struct passedcourses{
		char course[20];
		struct passedcourses* next;};
}student;

typedef struct studentarray{
	student* array;
	int capacity;
	int size;
}studarr;

int init(studarr*sa,int max){
	sa->capacity=max;
	sa->size=0;
	if (sa->capacity >=0){
		sa->array=(student*) malloc(sa->capacity*sizeof(student));
		return 1;}
	else{ 
		return 0;}
	}

int addElem(studarr*sa, student s){
	if (sa->size < sa->capacity){
		sa->array[sa->size]=s;
		sa->size++;
		return 1;
	}
	else
		return 0;
}

int removeElem(studarr*sa,int i){
//	sa->array[i]=NULL;
	for (int j=i;j<sa->size-1;j++){
		sa->array[j]=sa->array[j+1];
	}
	sa->array[sa->size]=(student){"","",-1,-1,NULL};
	sa->size--;
return 1;
}

void freesa(studarr*sa){
	free(sa->array);
	sa->array=NULL;
	sa->size=0;
	sa->capacity=0;
}



