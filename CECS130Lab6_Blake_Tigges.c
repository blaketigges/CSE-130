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
	phonebook *tBook; // temp pointer 
	phonebook *dBook = malloc(10 * sizeof(phonebook)); // dynamic pointer
	int numOfContacts = 10;

	int opt = 0;
	while (opt != 4){
	printf("Phone Book Application\n    1) Add Friend \n    2) Delete Friend \n    3) Show phone book\n    4) Exit\n");
	printf("Enter option: ");
	scanf("%d", &opt);
	int c = 0;
	switch (opt){
		case 1: // Add first name, last name, and number, then increment c
			if (c == 10){ 
				tBook = realloc(dBook, (numOfContacts + 1) * sizeof(phonebook)); // reallocates memory if c = 10
				if (tBook == NULL){
					printf("Reallocation failed, out of memory!!\n"); // if realloc fails say it failed
				} else {
					dBook = tBook; // if realloc succeeds copy temp book to dynamic book
					numOfContacts++;
				}
			} 
			printf("Enter First Name: ");
			scanf("%s", dBook[c].firstName);
			printf("Enter Last Name: ");
			scanf("%s", dBook[c].lastName);
			printf("Enter Phone Number: ");
			scanf("%s", dBook[c].number);
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
			for (int i = 0; i < c; i++){
				printf("%s %s %s\n", dBook[i].firstName, dBook[i].lastName, dBook[i].number); 
			}
			break;
		}
	}
	free(dBook);
	return 0;
}
