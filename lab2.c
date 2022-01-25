/*
Lab 2 - Currency Conversion  
1/16/2022
Section 1A
Blake Tigges
*/
#include <stdio.h>

int main()
{
	//Declare Variables 
	float CUR = 0.0; 
	const float USD = 1.0, USD2EUR = 0.8762, USD2CAD = 1.25248, USD2AUD = 1.38645, USD2GBP = 0.73189, USD2CNY = 6.34553; // USD conversion rates from 1/18/2022
	
	// Request amount of currency
	printf("Enter the amount of currency to convert: \n");
	// scanf("%f", &CUR);
	CUR = 1;
	
	// Convert the values
	printf("\t USD | EUR | CAD | AUD | GBP | CNY \n\n");
	printf("USD \t %.2f %.2f %.2f %.2f %.2f %.2f \n", USD * CUR, USD2EUR * CUR, USD2CAD * CUR, USD2AUD * CUR, USD2GBP * CUR, USD2CNY * CUR); // USD Conversions
	// printf("%.2f USD %.2f EUR %.2f CAD %.2f AUD %.2f GBP %.2f CNY \n", ); // EUR conversion
}
