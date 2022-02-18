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
	
	char *go[4] = {"outside", "to McDonalds", "to walmart", "to his basement"};
	char *his[4] = {"dog", "cat", "monkey", "toes"};
	char *from[4] = {"florida", "alaska", "peru", "africa"};
		
	srand(time(0));
	int randChoice = rand() % 4;
	
	printf("%s was a %s year old who like to go %s and play with his %s. He was born in %s, but once he became a clown he moved to clown town. ", name, age, go[randChoice], his[randChoice], from[randChoice] );
	printf("");
	return 0;
}
 
