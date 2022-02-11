/*
Lab 4 - Calculator Using Functions   
2/1/2022
Section 1A
Blake Tigges
*/
#include <stdio.h> 

// prototype all the functions 
void add(float x, float y);
void subtract(float x, float y);
void multiply(float x, float y);
void divide(float x, float y);
void modu(int z, int c);
void checkprime(int testnum);
void factorial(int x);
void power(float x, float y);
void fibonacci(int x); 

int main() {
	int opnum = -1; // create var for picking operation 
	while (opnum != 0) // exit when 7
	{
	float numone = 0; float numtwo = 0; int intone = 0; int inttwo = 0; // Set the float and integer variables 
	printf("Calculator Menu: \n(1) Addition \n(2) Subtraction \n(3) Multiplication \n(4) Division \n(5) Modulus (integers only) \n(6) Test if prime (integers only) \n(7) Factorial (integers only, under 20) \n(8) Power \n(9) Fibonacci Sequence (Up to 94)\n(0) Exit \n");// Display options
	printf("Enter operation number: \n"); // Ask for what to do
	scanf("%d", &opnum); // get input for opnum
	switch (opnum){
		case 1: 
			printf("Enter first number: ");		scanf("%f", &numone);
			printf("Enter second number: ");	scanf("%f", &numtwo);
			add(numone, numtwo); // Request 2 numbers then call the correct function
		break;
		case 2: 
			printf("Enter first number: ");		scanf("%f", &numone);
			printf("Enter second number: ");	scanf("%f", &numtwo);
			subtract(numone, numtwo); // Request 2 numbers then call the correct function
		break;
		case 3: 
			printf("Enter first number: ");		scanf("%f", &numone);
			printf("Enter second number: ");	scanf("%f", &numtwo);
			multiply(numone, numtwo); // Request 2 numbers then call the correct function
		break;
		case 4: 
			printf("Enter first number: ");		scanf("%f", &numone);
			printf("Enter second number: ");	scanf("%f", &numtwo);
			divide(numone, numtwo); // Request 2 numbers then call the correct function
		break;
		case 5: 
			printf("Enter first number: ");		scanf("%d", &intone);
			printf("Enter second number: ");	scanf("%d", &inttwo);
			modu(intone, inttwo); // Request 2 numbers then call the correct function
		break;
		case 6:			
	 		printf("Enter number to test: "); // Prime number checker
			scanf("%d", &intone);
			checkprime(intone);
		break;
		case 7:
			printf("Enter number: ");		scanf("%d", &intone);
			factorial(intone); // Request number then call the correct function
		break;
		case 8:
			printf("Enter first number: ");		scanf("%f", &numone);
			printf("Enter second number: ");	scanf("%f", &numtwo);
			power(numone, numtwo); // Request 2 numbers then call the correct function
		break;
		case 9:
			printf("Enter amount to compute: ");		scanf("%d", &intone);
			fibonacci(intone);
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
	printf("%f - %f = %f \n", x, y, x - y);  // Subtract the numbers and print 
}
void multiply(float x, float y){
	printf("%f x %f = %f \n", x, y, x * y); // Multiply the numbers and print 
}
void divide(float x, float y){
	if (y == 0) {
		printf("You can't divide by zero \n");
	} else {
	printf("%f / %f = %f \n", x, y, x / y); // Divide the numbers and print 
	}
}
void modu(int z, int c){
	printf("%d mod %d = %d \n", z, c, z % c); // Mod the numbers and print 
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
void factorial(int x){
	int y = 0;
	unsigned long long int factorial = x; // make factorial = x 
	if (x >=20){
		x = 20;
	}
	if (x < 0){
		printf("Number must be greater than 0 \n");  // dont do negative factorials
	} else {
		for(y = x-1; y > 0; --y){ 
			factorial = factorial * y; // do the math on factorial instead of x
		} 
		printf("%d! is %llu \n", x, factorial);	// print the results
	}
	
}
void power(float x, float y){
	float o = x; // original x
	float p = y; // original power
	if (y > 0){
		for (y = y-1; y > 0; y--){ // positive exponent 
			x = x * o; 
		}
	} else if(y < 0){
		for (y = y+1; y<0; y++){ // negative exponent
			x = x * o;
		}
		x = 1/x; // invert it for the negative exponet 
	}
	printf("%f ^ %f is %f\n", o, p, x); // print results
}
void fibonacci(int x){
	unsigned long long int res[1000] = {0,1}; // set first 2 numbers as 0 and 1, only can hold up to 94th number
	int i = 2; // set count at 2 so it starts at 3 number of array
	int p = 0; 
	if (x >= 94){ // set x to 94 since the array cant hold numbers bigger than the 94th number 
		x = 94;
	} 
	for (i; i < x; i++){
		res[i] = res[i-1] + res[i-2]; // set every number after first 2 by adding the 2 before it 
	}
	printf("%d numbers of fibonacci sequence are ", x);
	for (p; p < x; p++){
		printf("%llu, ", res[p]); // print the amount of numbers asked for 
	}
	printf("\n");
		
} 

