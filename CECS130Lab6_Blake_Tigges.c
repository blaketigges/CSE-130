/*
Lab 6 - phonebook    
2/15/2022
Section 1A
Blake Tigges
*/
#include <stdio.h> 
#include <stdlib.h>

typedef struct
	{
		char firstName[80];
		char lastName[80];
		char number[11];
	} contact;

int main(){
	int opt = 0;
	contact arrayOfContacts;
	contact list; 
	int newcount = 100;
	list = realloc(arrayOfContacts , newcount * sizeof(contact) ); 
	while (opt != 4){
	printf("Phone Book Application\n    1) Add Friend \n    2) Delete Friend \n    3) Show phone book\n    4) Exit\n");
	scanf("What do you want to do? %d\n", &opt)
	switch(opt){
		case 1:
			
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	free(arrayOfContacts);
}
