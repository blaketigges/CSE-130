/*
Lab 5 - interactive story    
2/8/2022
Section 1A
Blake Tigges
*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){
	char name[100];
	printf("What is your name? "); // ask for name
	scanf("%s", name);
	
	char age[100];
	printf("What is your age? "); // ask for age
	scanf("%s", age);
	
	// sets of random words to use in story
	char *go[4] = {"outside", "to McDonalds", "to walmart", "to his basement"};
	char *his[4] = {"dog", "cat", "monkey", "toes"};
	char *from[4] = {"florida", "alaska", "england", "africa"};
	char *ending[4] = {"a meteor hit his house and he died.", "he turned into a meatball.", "the world ended.", "he floated off of the surface of the earth."};
	srand(time(0)); // seed random function
	int randChoice = rand() % 4; // pick random number between 0 and 3
	
	printf("\t %s was a %s year old who like to go %s and play with his %s. He was born in %s, but once he became a clown he moved to the bathroom at taco bell. ", name, age, go[randChoice], his[randChoice], from[randChoice] );
	printf("But then he had a project due for his class and didnt know what to write to make it long enough so he wrote about not knowing what to write. But then %s", ending[randChoice]);
	return 0;
}
 
