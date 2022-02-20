/*
Lab 6 - phonebook    
2/15/2022
Section 1A
Blake Tigges
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct phonebook{
		char firstName[80];
		char lastName[80];
		char number[11];
	};

int main(){
	int opt = 0;
	struct phonebook book[10];
	
	int c = 0;
	while (opt != 4){
	printf("Phone Book Application\n    1) Add Friend \n    2) Delete Friend \n    3) Show phone book\n    4) Exit\n");
	printf("Enter option: ");
	scanf("%d", &opt);
	switch (opt){
		case 1: // Add first name, last name, and number, then increment c
			printf("Enter First Name: ");
			scanf("%s", book[c].firstName);
			printf("Enter Last Name: ");
			scanf("%s", book[c].lastName);
			printf("Enter Phone Number: ");
			scanf("%s", book[c].number);
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
				if (strcmp(delFirst, book[i].firstName) == 0 && strcmp(delLast, book[i].lastName) == 0){
					for (int j = i; j < c; j++){
						book[j] = book[j+1];
					}
					printf("Deleted %s %s\n", delFirst, delLast);
					c--;
				}
			}
			break;
		case 3: // print out 0 through c
			for (int i = 0; i < c; i++){
				printf("%s %s %s\n", book[i].firstName, book[i].lastName, book[i].number);
			}
			break;
		}
	}

	int newcount = 100;
	// list = realloc(arrayOfContacts , newcount * sizeof(contact) ); 
	
//	free(book);
	return 0;
}
