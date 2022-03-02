/*
Lab 7 - phonebook+    
3/1/2022
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

void addContact(phonebook *book, int c, int numOfContacts);

int main(){
	int numOfContacts = 10; //number of contacts to start with
	phonebook *dBook = malloc(numOfContacts * sizeof(phonebook)); // dynamic pointer
	int c = 0; // current contact

	int opt = 0; 
	while (opt != 8){
	printf("Phone Book Application\n    1) Add Friend \n    2) Delete Friend \n    3) Show phone book\n    4) alphabetize the list\n    5) find phone number for given name\n    6) Randomly pick number to call\n    7) delete everyone\n    8) Exit\n");
	printf("Enter option: ");
	scanf("%d", &opt);
	switch (opt){
		case 1: // Add first name, last name, and number, then increment c
			addContact(dBook, c, numOfContacts);
			c++;
			numOfContacts++;
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
				if (strcmp(delFirst, dBook[i].firstName) == 0 && strcmp(delLast, dBook[i].lastName) == 0){ // find if entered name is in book
					for (int j = i; j < c; j++){
						dBook[j] = dBook[j+1]; // if so move everything back one
					}
					printf("Deleted %s %s\n", delFirst, delLast); 
					c--;
				}
			}
			break;
		case 3: // print out 0 through c
			printf("Contacts: \n");
			for (int k = 0; k < c; k++){
				printf("%s %s %s\n", dBook[k].firstName, dBook[k].lastName, dBook[k].number); // print contacts through c 
			}
			break;
		case 4: // alphabetically sort contacts by name (first or last)
			printf("Contacts: \n");
			break;
		case 5: // find phone number by name
			
			break;
		case 6: // randomly select a contact and print out their name and number
			break;
		case 7: // delete all contacts
			break;
		}
	}
	free(dBook); // free memory
	return 0;
}

void addContact(phonebook *dBook, int c, int numOfContacts){
	phonebook *tBook; // temp pointer 
	if (c == numOfContacts){ 
		tBook = realloc(dBook, (numOfContacts + 1) * sizeof(phonebook)); // reallocates memory if c = 10
		if (tBook == NULL){
			printf("Reallocation failed, out of memory!!\n"); // if realloc fails say it failed
		} else {
			dBook = tBook; // if realloc succeeds copy temp book to dynamic book
		}
	} 
	printf("Enter First Name: ");
	scanf("%s", dBook[c].firstName);
	printf("Enter Last Name: ");
	scanf("%s", dBook[c].lastName);
	printf("Enter Phone Number: ");
	scanf("%s", dBook[c].number);
	printf("Contact added %s %s #%s\n", dBook[c].firstName, dBook[c].lastName, dBook[c].number); // confirm contact added
}