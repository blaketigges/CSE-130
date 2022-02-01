/*
Lab 4 - Function Calculator   
2/1/2022
Section 1A
Blake Tigges
*/
#include <stdio.h>

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
int mod(int, int);
int checkprime(int);
int factorial(int, int);
float power(float, float);
float customfunc(float, float);

int main() {
	int opnum = -1; // create var for picking operation 
	while (opnum != 0) // exit when 7
	{
	float numone = 0; float numtwo = 0; int intone = 0; int inttwo = 0; // Set the float and integer variables 
	printf("Calculator Menu: \n(1) Addition \n(2) Subtraction \n(3) Multiplication \n(4) Division \n(5) Modulus (integers only) \n(6) Test if prime (integers only) \n(7) Factorial (integers only) \n(8) Power \n(9) Your function \n(0) Exit \n");// Display options
	printf("Enter operation number: \n"); // Ask for what to do
	scanf("%d", &opnum); // get input for opnum
}
