/*
Lab 3 - Calculator   
1/25/2022
Section 1A
Blake Tigges
*/
#include <stdio.h>

int main() // Main Function 
{
	int opnum = 0;
	while (opnum != 7)
	{
	float numone = 0; float numtwo = 0; int intone = 0; int inttwo = 0; // Set the float and inte
	printf("Pick a function: \n (1) Addition \n (2) Subtraction \n (3) Multiplication \n (4) Division \n (5) Modulus (integers only) \n (6) Test if prime (integers only) \n (7) Exit ");
	printf("Enter operation number: \n");
	scanf("%d", &opnum);
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
		int primecheck1 = 0; int primecheck2 = 0;
		if (intone == 1){
			printf("Not prime 1 x 1 = 1");
			break;
		} 
		else if (intone == 0){
			printf("Not prime 0 x 1 = 0");
			break;
		}
		while (intone % primecheck1 != 0 && primecheck1 < 2000000000){
			primecheck1++;
			if (primecheck1 == intone){ // make sure it isnt using number as factor for itself 
				primecheck1++;
			}
		}
		while (primecheck1 * primecheck2 != intone && primecheck2 < 2000000000){
			primecheck2++;
			if (primecheck2 == intone){ // make sure it isnt using number as factor for itself 
				primecheck2++; 
			}
		}
		if (primecheck1 * primecheck2 != intone){
			printf("Prime!\n"); // Print prime if it is prime 
			break;
		}
		else {
			printf("Not prime %d x %d = %d \n", primecheck1, primecheck2, intone); // Print factors is not prime
		}
		break;

	}
	}
	printf("Good Bye!");
}
