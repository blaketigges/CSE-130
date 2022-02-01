/*
Lab 3 - Calculator   
1/25/2022
Section 1A
Blake Tigges
*/
#include <stdio.h>

int main() // Main Function 
{
	int opnum = 0; // create var for picking operation 
	while (opnum != 7) // exit when 7
	{
	float numone = 0; float numtwo = 0; int intone = 0; int inttwo = 0; // Set the float and integer variables 
	printf("Calculator Menu: \n(1) Addition \n(2) Subtraction \n(3) Multiplication \n(4) Division \n(5) Modulus (integers only) \n(6) Test if prime (integers only) \n(7) Exit \n");// Display options
	printf("Enter operation number: \n"); // Ask for what to do
	scanf("%d", &opnum); // get input for opnum
	switch (opnum){
		case 1: printf("Enter first number: "); // Addition operation
			scanf("%f", &numone);
			printf("Enter second number: ");
			scanf("%f", &numtwo);
			printf("%f + %f = %f \n", numone, numtwo, numone + numtwo); // Add the numbers and print 
		break;
		case 2: printf("Enter first number: "); // Subtraction operation
			scanf("%f", &numone);
			printf("Enter second number: ");
			scanf("%f", &numtwo);
			printf("%f - %f = %f \n", numone, numtwo, numone - numtwo);  // Subtract the numbers and print 
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
		case 6: printf("Enter number to test: "); // Prime number checker
			scanf("%d", &intone);
			int primecheck1 = 2; int primecheck2 = 2;
			while (intone % primecheck1 != 0 && primecheck1 < 9){ // check if there is a remainder when dividing input number by primecheck1 if there is then increase and try again till remainder is 0 
				primecheck1++;
				if (primecheck1 == intone){ // make sure it isnt using number as factor for itself 
					primecheck1++;
				}
			}
			while (primecheck1 * primecheck2 != intone && primecheck2 < 200000000){ // Once you have one of the factors of input number see if you can multiple it with primecheck2 to get input number, if not increase and try again
				primecheck2++;
				if (primecheck2 == intone){ // make sure it isnt using number as factor for itself 
					primecheck2++; 
				}
			}
			if (primecheck1 * primecheck2 != intone){
				primecheck2 = -2; // set primecheck2 to -2 to check if its negative number
				while (primecheck1 * primecheck2 != intone && primecheck2 > -200000000){ // Same as above but negative 
					primecheck2--;
					if (primecheck2 == intone){ // make sure it isnt using number as factor for itself 
						primecheck2--; 
					}
				}
			}
			if (primecheck1 * primecheck2 == intone){ 
				printf("Not prime %d x %d = %d \n\n", primecheck1, primecheck2, intone); // Print factors if not prime
				break;
			}
			else if (intone == 1){ // keep it from saying 1 or 0 is prime
				printf("Not prime 1 x 1 = 1\n\n");
			break;
			}
			else if (intone == -1){
				printf("Not prime -1 x 1 = -1\n\n");
				break;
			}
			else if (intone == 0){
				printf("Not prime 0 x 2 = 0\n\n");
				break;
			}
			else {
				printf("Prime!\n\n"); // Print prime if it is prime 
			}
			break;	
		}
	}
	printf("Good Bye!"); // exit
	return(0);
}
