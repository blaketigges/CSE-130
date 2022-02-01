/*
Lab 4 - Function Calculator   
2/1/2022
Section 1A
Blake Tigges
*/
#include <stdio.h>

void add();
void subtract();
void multiply();
void divide();
void mod();
void checkprime();
void factorial();
void power();
void customfunc();

int main() {
	int opnum = -1; // create var for picking operation 
	while (opnum != 0) // exit when 7
	{
	float numone = 0; float numtwo = 0; int intone = 0; int inttwo = 0; // Set the float and integer variables 
	printf("Calculator Menu: \n(1) Addition \n(2) Subtraction \n(3) Multiplication \n(4) Division \n(5) Modulus (integers only) \n(6) Test if prime (integers only) \n(7) Factorial (integers only) \n(8) Power \n(9) Your function \n(0) Exit \n");// Display options
	printf("Enter operation number: \n"); // Ask for what to do
	scanf("%d", &opnum); // get input for opnum
	switch (opnum){
		case 1: 
			add();
		break;
		case 2: 
			subtract();
		break;
		case 3: printf("Enter first number: "); // Multiplication Operation
			scanf("%f", &numone);
			printf("Enter second number: ");
			scanf("%f", &numtwo);
			printf("%f x %f = %f \n", numone, numtwo, numone * numtwo); // Multiply the numbers and print 
		break;
		case 4: printf("Enter first number: "); // Division operation
			scanf("%f", &numone);
			printf("Enter second number: ");
			scanf("%f", &numtwo);
			printf("%f / %f = %f \n", numone, numtwo, numone / numtwo); // Divide the numbers and print 
		break;
		case 5: printf("Enter first number: "); // Modulus operation
			scanf("%d", &intone);
			printf("Enter second number: ");
			scanf("%d", &inttwo);
			printf("%d mod %d = %d \n", intone, inttwo, intone % inttwo); // Mod the numbers and print 
		break;
		}
	}
}

void add() {
	float numone = 0; float numtwo = 0;
	printf("Enter first number: "); // Addition operation
	scanf("%f", &numone);
	printf("Enter second number: ");
	scanf("%f", &numtwo);
	printf("%f + %f = %f \n", numone, numtwo, numone + numtwo); // Add the numbers and print 
}
void subtract(){
	float numone = 0; float numtwo = 0;
	printf("Enter first number: "); // Subtraction operation
	scanf("%f", &numone);
	printf("Enter second number: ");
	scanf("%f", &numtwo);
	printf("%f - %f = %f \n", numone, numtwo, numone - numtwo);  // Subtract the numbers and print 
}
void multiply(){
	float numone = 0; float numtwo = 0;

}
void divide(){
	float numone = 0; float numtwo = 0;

}
void mod(){
	int intone = 0; int inttwo = 0;

}
void checkprime(){
	int intone = 0;

}
void factorial(){
	int intone = 0; int inttwo = 0;

}
void power(){
	float numone = 0; float numtwo = 0;

}
void customfunc(){
	float numone = 0; float numtwo = 0;

}


