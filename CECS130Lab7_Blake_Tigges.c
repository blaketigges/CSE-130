/*
Lab 7 - phonebook+    
3/1/2022
Section 1A
Blake Tigges
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
		char firstName[80];
		char lastName[80];
		char number[11];
	} phonebook;

void addContact(phonebook *book, int c, int numOfContacts);
void deleteContact(phonebook *book, int c, int numOfContacts);
void printAllContacts(phonebook *book, int c);
void alphabetizeContacts(phonebook *book, int c);
void findNumber(phonebook *book, int c);
void selectRandomContact(phonebook *book, int c);
void deleteAllContacts(phonebook *book, int c);

int main(){
	int numOfContacts = 3; //number of contacts to start with
	phonebook *dBook = malloc(numOfContacts * sizeof(phonebook)); // dynamic pointer
	int c = 0; // current contact

	int opt = 0; 
	while (opt != 8){
	printf("Phone Book Application\n    1) Add Friend \n    2) Delete Friend \n    3) Show phone book\n    4) Alphabetize the list\n    5) Find phone number for given name\n    6) Randomly pick number to call\n    7) Delete everyone\n    8) Exit\n");
	printf("Enter option: ");
	scanf("%d", &opt);
	switch (opt){
		case 1: // Add first name, last name, and number, then increment c
			addContact(dBook, c, numOfContacts);
			c++;
			numOfContacts++;
			break;
		case 2: // ask who to delete, then move everything down one, then decrease c
			if (c == 0){
				printf("Your contacts are empty\n");
				break;
			}
			deleteContact(dBook, c, numOfContacts);
			c--;
			break;
		case 3: // print out 0 through c
			printAllContacts(dBook, c);
			break;
		case 4: // alphabetically sort contacts by name (first or last)
			if (c == 0){
				printf("Your contacts are empty\n");
				break;
			}
			alphabetizeContacts(dBook, c);
			printAllContacts(dBook, c);
			break;
		case 5: // find phone number by name
			if (c == 0){
				printf("Your contacts are empty\n");
				break;
			}
			findNumber(dBook, c);
			break;
		case 6: // randomly select a contact and print out their name and number
			if (c == 0){
				printf("Your contacts are empty\n");
				break;
			}
			selectRandomContact(dBook, c);
			break;
		case 7: // delete all contacts
			deleteAllContacts(dBook, c);
			c = 0;
			numOfContacts = 3;
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
void deleteContact(phonebook *dBook, int c, int numOfContacts){
	printf("Who do you want to delete?\n");
	char delFirst[80];
	printf("Enter First Name: ");
	scanf("%s", delFirst);
	char delLast[80];
	printf("Enter Last Name: ");
	scanf("%s", delLast);
	int i;
	for (i = 0; i < c; i++){
		if (strcmp(delFirst, dBook[i].firstName) == 0 && strcmp(delLast, dBook[i].lastName) == 0){ // find if entered name is in book
			int j;
			for (j = i; j < c; j++){
				dBook[j] = dBook[j+1]; // if so move everything back one
			}
			printf("Deleted %s %s\n", delFirst, delLast); 
		}
	}
}
void printAllContacts(phonebook *dBook, int c){
	printf("Contacts: \n");
	int k;
	for (k = 0; k < c; k++){
		printf("%s %s %s\n", dBook[k].firstName, dBook[k].lastName, dBook[k].number); // print contacts through c 
	}
}

void alphabetizeContacts(phonebook *dBook, int c){
	printf("Sort by first or last?\n");
	char sort[80];
	printf("Enter choice: ");
	scanf("%s", sort);
	if (strcmp(sort, "first") == 0){
		int i, j;
		for (i = 0; i < c; i++){
			for (j = i + 1; j < c; j++){
				if (strcmp(dBook[i].firstName, dBook[j].firstName) > 0){
					phonebook temp = dBook[i];
					dBook[i] = dBook[j];
					dBook[j] = temp;
				}
			}
		}
	} else if (strcmp(sort, "last") == 0){
		int i, j;
		for (i = 0; i < c; i++){
			for (j = i + 1; j < c; j++){
				if (strcmp(dBook[i].lastName, dBook[j].lastName) > 0){
					phonebook temp = dBook[i];
					dBook[i] = dBook[j];
					dBook[j] = temp;
				}
			}
		}
	} else {
		printf("Invalid, pick first or last.\n");
	}
}
void findNumber(phonebook *dBook, int c){
	char findFirst[80];
	printf("Enter First Name: ");
	scanf("%s", findFirst);
	char findLast[80];
	printf("Enter Last Name: ");
	scanf("%s", findLast);
	int i;
	for (i = 0; i < c; i++){
		if (strcmp(findFirst, dBook[i].firstName) == 0 && strcmp(findLast, dBook[i].lastName) == 0){ // if name is in list
			printf("First: %s \nLast:%s \n#%s\n", dBook[i].firstName, dBook[i].lastName, dBook[i].number); // print found name and number
		}
	}
}
void selectRandomContact(phonebook *dBook, int c){
	srand(time(0)); // seed random number generator
	int r = rand() % c; // generate random number between 0 and c
	printf("%s %s %s\n", dBook[r].firstName, dBook[r].lastName, dBook[r].number); // print random contact
}
void deleteAllContacts(phonebook *dBook, int c){
	int i;
	for (i = 0; i < c; i++){
		dBook[i].firstName[0] = '\0';
		dBook[i].lastName[0] = '\0';
		dBook[i].number[0] = '\0';
	}
	printf("All contacts deleted\n");
}
