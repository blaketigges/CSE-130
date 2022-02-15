/*
Lab 5 - interactive story    
2/8/2022
Section 1A
Blake Tigges
*/
#include <stdio.h> 
#include <stdlib.h>

int main(){
	char name[100];
	printf("What is your name? ");
	scanf("%s", name);
	
	char age[100];
	printf("What is your age? ");
	scanf("%s", age);
	
	char desc[100];
	printf("What is a word to describe yourself? ");
	scanf("%s", desc);
	
	char *act[4] = {"eat", "swim", "c", "b"};
	srand(time(0));
	int randChoice = rand() % 4;
	
	
	printf("%s is a %s %s year old who likes to %s", name, desc, age, act[randChoice]);
	return 0;
}
