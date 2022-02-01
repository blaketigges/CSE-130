/*
Lab 4 - Calculator Using Functions   
2/1/2022
Section 1A
Blake Tigges
*/
#include <stdio.h>

void add(float x, float y);
void subtract(float x, float y);
void multiply(float x, float y);
void divide(float x, float y);
void mod(int x, int y);
void checkprime(int testnum);
void factorial(int x, int y);
void power(float x, float y);
void customfunc(float x, float y);

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
			printf("Enter first number: ");		scanf("%f", &numone);
			printf("Enter second number: ");	scanf("%f", &numtwo);
			add(numone, numtwo);
		break;
		case 2: 
			subtract(numone, numtwo);
		break;
		case 3: 
			multiply(numone, numtwo);
		break;
		case 4: 
			divide(numone, numtwo);
		break;
		case 5: 
			mod(intone, inttwo);
		break;
		case 6:			
	 		printf("Enter number to test: "); // Prime number checker
			scanf("%d", &intone);
			checkprime(intone);
		break;
		case 7:
			factorial(intone, inttwo);
		break;
		case 8:
			power(numone, numtwo);
		break;
		case 9:
			customfunc(numone, numtwo);
		break;
		}
	}
	printf("Good Bye!"); // exit
	return(0);
}

void add(float x, float y) {
	printf("%f + %f = %f \n", x, y, x + y); // Add the numbers and print 
} 
void subtract(float x, float y){
	float numone = 0; float numtwo = 0;
	printf("Enter first number: "); // Subtraction operation
	scanf("%f", &numone);
	printf("Enter second number: ");
	scanf("%f", &numtwo);
	printf("%f - %f = %f \n", numone, numtwo, numone - numtwo);  // Subtract the numbers and print 
}
void multiply(float x, float y){
	float numone = 0; float numtwo = 0;
	printf("Enter first number: "); // Multiplication Operation
	scanf("%f", &numone);
	printf("Enter second number: ");
	scanf("%f", &numtwo);
	printf("%f x %f = %f \n", numone, numtwo, numone * numtwo); // Multiply the numbers and print 
}
void divide(float x, float y){
	float numone = 0; float numtwo = 0;
	printf("Enter first number: "); // Division operation
	scanf("%f", &numone);
	printf("Enter second number: ");
	scanf("%f", &numtwo);
	printf("%f / %f = %f \n", numone, numtwo, numone / numtwo); // Divide the numbers and print 
}
void mod(int x, int y){
	int intone = 0; int inttwo = 0;
	printf("Enter first number: "); // Modulus operation
	scanf("%d", &intone);
	printf("Enter second number: ");
	scanf("%d", &inttwo);
	printf("%d mod %d = %d \n", intone, inttwo, intone % inttwo); // Mod the numbers and print 
}
void checkprime(int testnum){
	int primecheck1 = 2; int primecheck2 = 2;
		while (testnum % primecheck1 != 0 && primecheck1 < 9){ // check if there is a remainder when dividing input number by primecheck1 if there is then increase and try again till remainder is 0 
			primecheck1++;
			if (primecheck1 == testnum){ // make sure it isnt using number as factor for itself 
				primecheck1++;
			}
		}
		while (primecheck1 * primecheck2 != testnum && primecheck2 < 200000000){ // Once you have one of the factors of input number see if you can multiple it with primecheck2 to get input number, if not increase and try again
			primecheck2++;
			if (primecheck2 == testnum){ // make sure it isnt using number as factor for itself 
				primecheck2++; 
			}
		}
		if (primecheck1 * primecheck2 != testnum){
			primecheck2 = -2; // set primecheck2 to -2 to check if its negative number
			while (primecheck1 * primecheck2 != testnum && primecheck2 > -200000000){ // Same as above but negative 
				primecheck2--;
				if (primecheck2 == testnum){ // make sure it isnt using number as factor for itself 
					primecheck2--; 
				}
			}
		}
		if (primecheck1 * primecheck2 == testnum){ 
			printf("Not prime %d x %d = %d \n\n", primecheck1, primecheck2, testnum); // Print factors if not prime
		}
		else if (testnum == 1){ // keep it from saying 1 or 0 is prime
			printf("Not prime 1 x 1 = 1\n\n");
		}
		else if (testnum == -1){
		printf("Not prime -1 x 1 = -1\n\n");
		}
		else if (testnum == 0){
				printf("Not prime 0 x 2 = 0\n\n");
		}
		else {
			printf("Prime!\n\n"); // Print prime if it is prime 
		}
}
void factorial(int x, int y){
	int intone = 0; int inttwo = 0;

}
void power(float x, float y){
	float numone = 0; float numtwo = 0;

}
void customfunc(float x, float y){
	float numone = 0; float numtwo = 0;

}


