/*
Lab 6 - phonebook    
2/15/2022
Section 1A
Blake Tigges
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct{
		char firstName[80];
		char lastName[80];
		char number[11];
	} phonebook;

int main(){
	int numOfContacts = 10; //number of contacts to start with
	phonebook *tBook; // temp pointer 
	phonebook *dBook = malloc(numOfContacts * sizeof(phonebook)); // dynamic pointer
	int c = 0; // current contact

	int opt = 0; 
	while (opt != 4){
	printf("Phone Book Application\n    1) Add Friend \n    2) Delete Friend \n    3) Show phone book\n    4) Exit\n");
	printf("Enter option: ");
	scanf("%d", &opt);
	switch (opt){
		case 1: // Add first name, last name, and number, then increment c
			if (c == numOfContacts){ 
				tBook = realloc(dBook, (numOfContacts + 1) * sizeof(phonebook)); // reallocates memory if c = 10
				if (tBook == NULL){
					printf("Reallocation failed, out of memory!!\n"); // if realloc fails say it failed
				} else {
					dBook = tBook; // if realloc succeeds copy temp book to dynamic book
					numOfContacts++;
				}
			} 
			printf("Enter First Name: ");
			scanf("%s", &dBook[c].firstName);
			printf("Enter Last Name: ");
			scanf("%s", &dBook[c].lastName);
			printf("Enter Phone Number: ");
			scanf("%s", &dBook[c].number);
			printf("Contact added %s %s #%s\n", dBook[c].firstName, dBook[c].lastName, dBook[c].number);
			c++;
			break;
		case 2: // ask who to delete, then move everything down one, then decrease c
			printf("Who do you want to delete?\n");
			char delFirst[80];
			printf("Enter First Name: ");
			scanf("%s", delFirst);
			char delLast[80];
			printf("Enter Last Name: ");
			scanf("%s", delLast);
			for (int i = 0; i < c; i++){
				if (strcmp(delFirst, dBook[i].firstName) == 0 && strcmp(delLast, dBook[i].lastName) == 0){
					for (int j = i; j < c; j++){
						dBook[j] = dBook[j+1];
					}
					printf("Deleted %s %s\n", delFirst, delLast);
					c--;
				}
			}
			break;
		case 3: // print out 0 through c
			printf("Phone Book \n");
			printf("c = %d\n", c);
			for (int k = 0; k < c; k++){
				printf("%s %s %s\n", dBook[k].firstName, dBook[k].lastName, dBook[k].number);
			}
			break;
		}
	}
	free(dBook);
	return 0;
}
